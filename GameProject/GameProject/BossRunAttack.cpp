#include"BossRunAttack.h"
#include"BossDead.h"


const VECTOR BossRunAttack::OffsetCollisionPosition = VGet(0.0f, 20.0f, 0.0f);

///<summary>
///コンストラクタ
///</summary>
BossRunAttack::BossRunAttack(int& InitializeModelHandle, const int beforeAnimationIndex)
    :StateBase(InitializeModelHandle, Boss::Run, beforeAnimationIndex)
{
    //アニメーション速度の初期化
    animationSpeed = InitializeAnimationSpeed;
    //インプットマネージャーのインスタンスをもってくる
    inputManager = InputManager::GetInstance();

    // 当たり判定を開始させるアニメーションの再生率を代入
    collisionStratAnimationRatio = CollisionStratAnimationRatio;

    // 当たり判定をずらす量を代入
    offsetPositionScale = OffsetCollisionPositonScale;

    //当たり判定をどれだけずらすかの座標を代入
    offsetPosition      = OffsetCollisionPosition;
}

/// <summary>
/// デストラクタ
/// </summary>
BossRunAttack::~BossRunAttack()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void BossRunAttack::Update(VECTOR& modelDirection, VECTOR& position,const VECTOR targetPosition,VECTOR cameraPosition)
{
    //ステートの切り替え処理を呼ぶ
    ChangeState();

    //アニメーションの再生時間のセット
    UpdateAnimation();

    // FIXME :
    // アニメーション終了時ではなくボスの行動が終わったら二修正する必要性あり
    //if (currentPlayAnimationState == FirstRoopEnd)
    //{
    //    collisionData.collisionState = CollisionData::CollisionEnded;
    //}

    //当たり判定に必要な情報の更新
    UpdateCollisionData(modelDirection, position);

    //アニメーションの再生割合を調べて当たり判定情報をCollisionManagerに送信する
    SendCollisionDataByAnimationTime(animationNowTime, animationLimitTime);

    //シーンが切り替わっていればアニメーションをデタッチ
    DetachAnimation();

}


/// <summary>
/// ステートの切り替え処理をまとめたもの
/// </summary>
void BossRunAttack::ChangeState()
{
    //ToDo
    //BossのAIを作るまではボタンでステートが遷移するようにしている
    if (inputManager->GetKeyPushState(InputManager::LeftStick) == InputManager::JustRelease)
    {
        nextState = new BossDead(modelhandle, this->GetAnimationIndex());
    }
    else
    {
        nextState = this;
    }
}

/// <summary>
/// 座標などを当たり判定に必要なデータに変換
/// </summary>
/// <param name="modelDirection">モデルの向いている方向</param>
void BossRunAttack::UpdateCollisionData(const VECTOR& modelDirection, const VECTOR characterPosition)
{
    //当たり判定の座標を移動させる
    TransrateCollisionCapsulePosition(characterPosition, modelDirection);

    //中央座標の代入
    collisionData.centerPosition = position;

    //カプセルの下側の座標
    collisionData.bottomPosition = position;

    //カプセルの上側の座標
    collisionData.upPosition = position;

    //カプセルの球部分の半径
    collisionData.radius = CollisionRadius;

    //オブジェクトの種類
    collisionData.hitObjectTag = CollisionManager::BossDefaultAttack;

    //当たった際の関数
    collisionData.onHit = std::bind(&BossRunAttack::OnHit, this, std::placeholders::_1);

    //当たった際のダメージ量
    collisionData.damageAmount = DamageAmount;
}


/// <summary>
/// 当たった時の処理
/// </summary>
/// <param name="targetCollisionData">当たった相手の当たり判定情報</param>
void BossRunAttack::OnHit(CollisionData targetCollisionData)
{
    //当たり判定を消す
    collisionData.collisionState = CollisionData::CollisionEnded;
}


#ifdef _DEBUG

/// <summary>
/// 当たり判定を描画する(デバッグ用)
/// </summary>
void BossRunAttack::DrawCollision()
{
    if (collisionData.collisionState == CollisionData::CollisionActive)
    {
        //当たり判定が正しいかの確認用の描画
        DrawSphere3D(collisionData.centerPosition, collisionData.radius, 16, GetColor(255, 0, 0), GetColor(255, 0, 0), FALSE);
    }
}
#endif // _DEBUG
