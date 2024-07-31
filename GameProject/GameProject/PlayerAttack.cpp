#include"PlayerAttack.h"
#include"StateBase.h"
#include"Player.h"
#include"PlayerIdle.h"
#include"InputManager.h"


const VECTOR PlayerAttack::OffsetPositionY = VGet(0.0f,10.0f, 0.0f);

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="InitalModelHandle">モデルハンドル</param>
/// <param name="beforeAnimationIndex">前のステートでのアニメーション情報</param>
PlayerAttack::PlayerAttack(int InitalModelHandle, int beforeAnimationIndex, Player::AnimationState animationState)
    :StateBase(InitalModelHandle,animationState,beforeAnimationIndex)
    ,position(VGet(0.0f,0.0f,0.0f))
{
    //アニメーション速度の初期化
    animationSpeed = 1.0f;


    //コリジョンマネージャーのインスタンスをもってくる
    collisionManager = CollisionManager::GetInstance();



    //当たり判定用の変数の初期化
    ConvertCollisionData();

    //識別番号はCollisionManagerが代入するので入っていないことを
    registerTag = CollisionManager::NotRegisterTag;

}

/// <summary>
/// デストラクタ
/// </summary>
PlayerAttack::~PlayerAttack()
{
    //当たり判定情報を削除する
    collisionManager->DeleteResister(registerTag);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void PlayerAttack::Update(VECTOR& modelDirection, VECTOR& position)
{
    //当たり判定の座標を設定
    this->position = VAdd(VAdd(position,OffsetPositionY), VScale(modelDirection, OffsetPositionScale));

    //ステートの切り替え処理を呼ぶ
    ChangeState();
    //アニメーションの再生時間のセット
    UpdateAnimation();

    //当たり判定情報を渡す
    SendRegister();

    //シーンが切り替わっていればアニメーションをデタッチ
    DetachAnimation(this);

}

/// <summary>
/// ステートの切り替え処理をまとめたもの
/// </summary>
void PlayerAttack::ChangeState()
{
    //アニメーションの再生が終了したらステートを切り替える
    if (currentPlayAnimationState == FirstRoopEnd)
    {
        nextState = new PlayerIdle(modelhandle, animationIndex);
    }
    else
    {
        nextState = this;
    }
}


/// <summary>
/// プレイヤーの情報から当たり判定に必要な情報を出して代入
/// </summary>
void PlayerAttack::ConvertCollisionData()
{
    //中央座標の代入
    collisionData.centerPosition = position;
    //カプセルの下側の座標
    collisionData.bottomPosition = position;
    //カプセルの上側の座標
    collisionData.upPosition = VAdd(position, VGet(0.0f, CollisionCapsuleLineHalfLength, 0.0f));
    //カプセルの球部分の半径
    collisionData.radius = CollisionRadius;
    //オブジェクトの種類
    collisionData.hitObjectTag = CollisionManager::PlayerAttack;
    //当たった際の関数
    collisionData.onHit = std::bind(&PlayerAttack::OnHit, this, std::placeholders::_1);
}

/// <summary>
/// 当たり判定データの更新したものを送る
/// </summary>
void PlayerAttack::SendRegister()
{
    //現在のプレイヤー情報から当たり判定に必要な値に代入
    ConvertCollisionData();

    //コリジョンマネージャーに渡す
    collisionManager->SetResister(collisionData, registerTag);
}

/// <summary>
/// 当たった時の処理
/// </summary>
void PlayerAttack::OnHit(CollisionData collisionData)
{
    //当たったフラグをオンにする
    isHited = true;
}

#ifdef _DEBUG

void PlayerAttack::DrawCollision()
{
    //当たり判定が正しいかの確認用の描画
    DrawCapsule3D(collisionData.upPosition, collisionData.bottomPosition, collisionData.radius, 16, GetColor(255, 0, 0), GetColor(255, 0, 0), FALSE);
}
#endif // _DEBUG

