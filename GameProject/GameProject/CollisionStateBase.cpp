#include"CollisionData.h"
#include"CollisionManager.h"
#include"CollisionStateBase.h"


/// <summary>
/// コンストラクタ
/// </summary>
CollisionStateBase::CollisionStateBase()
    :position(VGet(0,0,0))
{
    //コリジョンマネージャーのインスタンスをもってくる
    collisionManager = CollisionManager::GetInstance();

    //当たり判定がまだ生成されていない状態
    collisionData.collisionState = CollisionData::NoCollision;
}

/// <summary>
/// デストラクタ
/// </summary>
CollisionStateBase::~CollisionStateBase()
{
    //処理なし
}


/// <summary>
/// アニメーションの再生時間に合わせて当たり判定情報を渡す
/// </summary>
void CollisionStateBase::SendCollisionDataByAnimationTime(float animationNowTime, float animationLimitTime)
{

    //アニメーションの再生時間が指定の割合を超えていたらCollisionManagerに情報を渡す
    if (animationNowTime / animationLimitTime >= collisionStratAnimationRatio &&
        collisionData.collisionState == CollisionData::NoCollision)
    {
        //当たり判定の状態を変更する
        collisionData.collisionState = CollisionData::CollisionActive;
        collisionManager->RegisterCollisionData(&collisionData);

    }
}

/// <summary>
/// キャラクターの座標から当たり判定を生成する場所を設定する
/// </summary>
/// <param name="characterPosition">キャラの座標</param>
/// <param name="direction">生成する方向</param>
void CollisionStateBase::TransrateCollisionCapsulePosition(VECTOR characterPosition,VECTOR direction)
{

    // 任意のベクトル (0, 1, 0) を使用して新しいX軸を定義
    VECTOR xAxis = VNorm(VCross(VGet(0.0f, 1.0f, 0.0f), direction));

    // 新しいY軸を計算
    VECTOR yAxis = VNorm(VCross(direction, xAxis));

    // 元となる座標からどの方向にどれだけ動くかのベロシティを計算する
    VECTOR velocity = VScale(direction, offsetPositionScale);

    //移送させた座標を出す
    VECTOR newPosition = VAdd(characterPosition, velocity);

    //移動させた方向軸を基準として動かせる行列を出す
    MATRIX changeAxisMatrix = MGetAxis1(xAxis, yAxis, direction, newPosition);

    //新しい軸を使って座標を移動させる
    VECTOR axisChangeOffsetPosition = VTransform(offsetPosition, changeAxisMatrix);


    // 平行移動させた位置を設定
    position =  axisChangeOffsetPosition;


}

/// <summary>
/// カプセルの回転させるベクトルの計算
/// </summary>
/// <param name="radian">ラジアン</param>
/// <returns>計算したベクトル</returns>
VECTOR CollisionStateBase::RotationCollisionCapsule(float radian, VECTOR modelDirection, VECTOR position, float capsuleLineLength)
{

    //回転用の行列を作成
    MATRIX capsuleAngle = MGetRotAxis(modelDirection, radian);

    //回転させる前のカプセルの終点座標（positionに垂直)
    VECTOR vertexCapsuleEndPosition = VAdd(position, VGet(0.0f, capsuleLineLength, 0.0f));

    //回転させる前のカプセルのラインベクトル
    VECTOR capsuleLineVector = VSub(vertexCapsuleEndPosition, position);

    //回転させた後のカプセルのラインベクトルを返す
    return VTransform(capsuleLineVector, capsuleAngle);
}
