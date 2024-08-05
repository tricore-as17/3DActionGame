#include "BossDefaultAttack.h"
#include"BossAreaAttack.h"
#include"Utility.h"

const VECTOR BossDefaultAttack::OffsetPosition = VGet(30.0f, 40.0f, 0.0f);

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

    //当たり判定を開始させる再生率の設定
    collisionStratAnimationRatio = InitializeCollisionStartAnimationRatio;

    //当たり判定をどれだけずらすかを設定
    offsetPosition = OffsetPosition;

    //当たり判定を向いている方向にどれだけ進めるかの値を設定
    offsetPositionScale = OffsetPositionScale;

    //インプットマネージャーをもってくる
    inputManager = InputManager::GetInstance();

}

/// <summary>
/// デストラクタ
/// </summary>
BossDefaultAttack::~BossDefaultAttack()
{
    //処理なし
}


/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void BossDefaultAttack::Update(VECTOR& modelDirection, VECTOR& characterPosition,const VECTOR targetPosition)
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
    UpdateCollisionData(modelDirection,characterPosition);

    //アニメーションの再生割合を調べて当たり判定情報をCollisionManagerに送信する
    SendCollisionDataByAnimationTime(GetAnimationNowTime(),GetAnimationLimitTime());

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
    //当たり判定を消す
    this->collisionData.collisionState = CollisionData::CollisionEnded;
}

/// <summary>
/// 座標などを当たり判定に必要なデータに変換
/// </summary>
void BossDefaultAttack::UpdateCollisionData(const VECTOR& modelDirection, const VECTOR characterPosition)
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
    collisionData.hitObjectTag = CollisionManager::BossDefaultAttack;

    //当たった際の関数
    collisionData.onHit = std::bind(&BossDefaultAttack::OnHit, this, std::placeholders::_1);

    //当たった際のダメージ量
    collisionData.damageAmount = DamageAmount;
    

}


#ifdef _DEBUG

void BossDefaultAttack::DrawCollision()
{
    if (collisionData.collisionState == CollisionData::CollisionActive)
    {
        //当たり判定が正しいかの確認用の描画
        DrawCapsule3D(collisionData.upPosition, collisionData.bottomPosition, collisionData.radius, 16, GetColor(255, 0, 0), GetColor(255, 0, 0), FALSE);
    }
}
#endif // _DEBUG


