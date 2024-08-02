#include "BossDefaultAttack.h"
#include"BossAreaAttack.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="InitializeModelHandle">ボスのモデルハンドル</param>
/// <param name="beforeAnimationIndex">前のステートでのアニメーション</param>
BossDefaultAttack::BossDefaultAttack(int& InitializeModelHandle, const int beforeAnimationIndex)
    :StateBase(InitializeModelHandle, Boss::Attack, beforeAnimationIndex)
{
    //アニメーション速度の初期化
    animationSpeed = InitializeAnimationSpeed;

    //インプットマネージャーをもってくる
    inputManager = InputManager::GetInstance();

    //コリジョンマネージャーのインスタンスをもってくる
    collisionManager = CollisionManager::GetInstance();

    //当たり判定用の変数の初期化
    UpdateCollisionData();

    //識別番号はCollisionManagerが代入するので入っていないことを
    //分かるように-1を代入
    registerTag = CollisionManager::NotRegisterTag;
}

/// <summary>
/// デストラクタ
/// </summary>
BossDefaultAttack::~BossDefaultAttack()
{
    //当たり判定情報を削除する
    collisionManager->DeleteResister(registerTag);
}


/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void BossDefaultAttack::Update(VECTOR& modelDirection, VECTOR& position)
{
    //ステートの切り替え処理を呼ぶ
    ChangeState();

    //アニメーションの再生時間のセット
    UpdateAnimation();

    //シーンが切り替わっていればアニメーションをデタッチ
    DetachAnimation(this);
}

/// <summary>
/// ステートの切り替え処理をまとめたもの
/// </summary>
void BossDefaultAttack::ChangeState()
{
    //ToDo
    //BossのAIを作るまではボタンでステートが遷移するようにしている
    if (inputManager->GetKeyPushState(InputManager::LeftStick) == InputManager::JustRelease)
    {
        //ボスの移動ステートに移行
        nextState = new BossAreaAttack(modelhandle, this->GetAnimationIndex());
    }
    else
    {
        nextState = this;
    }
}

/// <summary>
/// 当たった時の処理
/// </summary>
void BossDefaultAttack::OnHit(CollisionData collisionData)
{
    collisionManager->DeleteResister(registerTag);
}

/// <summary>
/// 座標などを当たり判定に必要なデータに変換
/// </summary>
void BossDefaultAttack::UpdateCollisionData()
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
    collisionData.hitObjectTag = CollisionManager::BossDefaultAttack;
    //当たった際の関数
    collisionData.onHit = std::bind(&BossDefaultAttack::OnHit, this, std::placeholders::_1);

}
