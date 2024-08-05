#include"PlayerAttack.h"
#include"StateBase.h"
#include"Player.h"
#include"PlayerIdle.h"
#include"InputManager.h"
#include"Utility.h"


const VECTOR PlayerAttack::OffsetPositionY = VGet(0.0f,10.0f, 0.0f);

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="InitalModelHandle">モデルハンドル</param>
/// <param name="beforeAnimationIndex">前のステートでのアニメーション情報</param>
PlayerAttack::PlayerAttack(int InitalModelHandle, int beforeAnimationIndex, Player::AnimationState animationState)
    :StateBase(InitalModelHandle,animationState,beforeAnimationIndex)
{
    //アニメーション速度の初期化
    animationSpeed = 1.0f;

    //当たり判定を開始させる再生率の設定
    collisionStratAnimationRatio = InitializeCollisionStartAnimationRatio;

    //当たり判定をどれだけずらすかを設定
    offsetPosition = VGet(-10, 10, 0);

    //当たり判定を向いている方向にどれだけ進めるかの値を設定
    offsetPositionScale = 20.0f;

}

/// <summary>
/// デストラクタ
/// </summary>
PlayerAttack::~PlayerAttack()
{
    //当たり判定情報を削除
    this->collisionData.collisionState = CollisionData::CollisionEnded;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="modelDirection">モデルの向き</param>
/// <param name="characterPosition">キャラクターの座標</param>
void PlayerAttack::Update(VECTOR& modelDirection, VECTOR& position,const VECTOR targetPosition,VECTOR cameraPosition)
{
 
    //ステートの切り替え処理を呼ぶ
    ChangeState();
    //アニメーションの再生時間のセット
    UpdateAnimation();

    //アニメーションが終了していたら当たり判定を消す
    if (currentPlayAnimationState == FirstRoopEnd)
    {
        collisionData.collisionState = CollisionData::CollisionEnded;
    }
    //当たり判定に必要な情報の更新
    UpdateCollisionData(modelDirection,position);

    //アニメーションの再生割合を調べて当たり判定情報をCollisionManagerに送信する
    SendCollisionDataByAnimationTime(GetAnimationNowTime(), GetAnimationLimitTime());

    //シーンが切り替わっていればアニメーションをデタッチ
    DetachAnimation();

}

/// <summary>
/// ステートの切り替え処理をまとめたもの
/// </summary>
void PlayerAttack::ChangeState()
{
    //アニメーションの再生が終了したらステートを切り替える
    if (currentPlayAnimationState == FirstRoopEnd)
    {
        nextState = new PlayerIdle(modelhandle, this->GetAnimationIndex());

    }
    else
    {
        nextState = this;
    }
}


/// <summary>
/// プレイヤーの情報から当たり判定に必要な情報を出して代入
/// </summary>
void PlayerAttack::UpdateCollisionData(const VECTOR& modelDirection,const VECTOR characterPosition)
{
    //当たり判定の座標を移動させる
    TransrateCollisionCapsulePosition(characterPosition, modelDirection);

    //角度からラジアンに変換する
    float radianAngle = Utility::ConvertRadian(CollisionCapsuleAngle);

    //カプセル回転用のベクトルを用意する
    VECTOR capsuleLineVector = RotationCollisionCapsule(radianAngle, modelDirection, position, CollisionCapsuleLineHalfLength);

    //中央座標の代入
    collisionData.centerPosition = position;
    //カプセルの下側の座標
    collisionData.bottomPosition = position;
    //カプセルの上側の座標
    collisionData.upPosition = VAdd(position, capsuleLineVector);
    //カプセルの球部分の半径
    collisionData.radius = CollisionRadius;
    //オブジェクトの種類
    collisionData.hitObjectTag = CollisionManager::PlayerAttack;
    //当たった際の関数
    collisionData.onHit = std::bind(&PlayerAttack::OnHit, this, std::placeholders::_1);
    //当たった際のダメージ量
    collisionData.damageAmount = DamageAmount;
}


/// <summary>
/// 当たった時の処理
/// </summary>
void PlayerAttack::OnHit(CollisionData collisionData)
{
    switch (collisionData.hitObjectTag)
    {
    case CollisionManager::Boss:
        break;
    default:
        break;
    }
    //当たったフラグをオンにする
    this->collisionData.collisionState = CollisionData::CollisionEnded;
}

#ifdef _DEBUG

void PlayerAttack::DrawCollision()
{
    if (collisionData.collisionState == CollisionData::CollisionActive)
    {
        //当たり判定が正しいかの確認用の描画
        DrawCapsule3D(collisionData.upPosition, collisionData.bottomPosition, collisionData.radius, 16, GetColor(255, 0, 0), GetColor(255, 0, 0), FALSE);
    }
}
#endif // _DEBUG

