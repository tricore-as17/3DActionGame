#include"DxLib.h"
#include "CollisionManager.h"
#include"CollisionData.h"
#include"Utility.h"

//nullポインターを入れる
CollisionManager* CollisionManager::collisionManager = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
CollisionManager::CollisionManager()
{

}

/// <summary>
/// デストラクタ
/// </summary>
CollisionManager::~CollisionManager()
{
    //hitObjectListの削除
    hitObjectList.clear();
}

/// <summary>
/// インスタンスを作成する
/// </summary>
void CollisionManager::CreateInstance()
{
    //既にインスタンスが確保されているかのチェック
    if (collisionManager != nullptr)
    {
        return;
    }

    //シングルトンの作成
    collisionManager = new CollisionManager();
}

/// <summary>
/// インスタンスの削除
/// </summary>
void CollisionManager::DeleteInstance()
{
    if (collisionManager)
    {
        delete collisionManager;
    }
    //シングルトンの作成
    collisionManager = nullptr;
}



/// <summary>
/// 球体とカプセルとの当たり判定
/// </summary>
/// <param name="sphere">球体の当たり判定に必要な情報</param>
/// <param name="capsule">カプセルの当たり判定に必要な情報</param>
/// <returns>当たっているか</returns>
bool CollisionManager::IsHitSphereAndCapsule(CollisionData sphere, CollisionData capsule)
{
    // カプセルの線分ベクトル
    VECTOR capsuleLine = VSub(capsule.bottomPosition, capsule.upPosition);
    // 線分の長さ
    float lineLength = CalculationDistance(capsule.upPosition, capsule.bottomPosition);

    // 球体の中心からカプセルの始点へのベクトル
    VECTOR toSphere = VSub(sphere.centerPosition, capsule.upPosition);
    // 線分上の最近接点のパラメータ
    float lineNearestPoint = VDot(toSphere, capsuleLine) / VDot(capsuleLine, capsuleLine);

    // 線分上の最近接点が線分の範囲内に収まるように制限
    if (lineNearestPoint < 0.0f) lineNearestPoint = 0.0f;
    if (lineNearestPoint > 1.0f) lineNearestPoint = 1.0f;

    // 線分上の最近接点を計算
    VECTOR closestPoint = VAdd(capsule.upPosition, VScale(capsuleLine, lineNearestPoint));
    // 球体の中心から最近接点までの距離を計算
    float distanceToSphere = CalculationDistance(sphere.centerPosition, closestPoint);

    // 衝突判定（カプセルの半径と球体の半径の和と距離を比較）
    return distanceToSphere <= (capsule.radius + sphere.radius);
}

/// <summary>
/// カプセル同士の当たり判定
/// </summary>
/// <param name="collider">衝突を検知する側の情報</param>
/// <param name="target">目標の情報</param>
/// <returns>当たったか</returns>
bool CollisionManager::IsHitCapsuleAndCapsule(const CollisionData collider, const CollisionData target)
{

    bool isHited = false;

    //線分の最短距離を計算
    float distance = Segment_Segment_MinLength(collider.upPosition, collider.bottomPosition,target.upPosition , target.bottomPosition);

    //半径の合計を出す
    float radiusSum = collider.radius + target.radius;

    //半径より小さいかの確認
    if (distance <= radiusSum)
    {
        isHited = true;
    }

    return isHited;
}




/// <summary>
/// 当たり判定データのポインタを渡す
/// </summary>
/// <param name="data"></param>
void CollisionManager::RegisterCollisionData(CollisionData* data)
{
    //オブジェクトの追加
    hitObjectList.emplace_back(data);
}



/// <summary>
/// 地面に向けたベクトルの調整
/// </summary>
/// <param name="velocity">プレイヤーのベロシティ</param>
/// <param name="beforePosition">反映させる前の座標</param>
/// <returns>調整したベロシティ</returns>
VECTOR CollisionManager::AdjustGroundToWardVelocity(VECTOR velocity, VECTOR beforePosition)
{

    VECTOR adjustVelocity = velocity;
    //地面にめり込まなくなるまで戻す
    while (true)
    {
        //未来のY座標を出す
        float futureYPosition = beforePosition.y + adjustVelocity.y;
        //座標が0より下回っていたら修正する
        if (futureYPosition < 0)
        {
            adjustVelocity.y += AdjustVelocityY;
        }
        else
        {

            break;
        }

    }

    //調整した値を返す
    return adjustVelocity;
}


/// <summary>
/// 更新処理
/// </summary>
void CollisionManager::Update()
{
    //オブジェクトの数二つ分をまわす
    for (int i = 0; i < hitObjectList.size(); i++)
    {

        for (int j = 0; j < hitObjectList.size(); j++)
        {
            //当たったかを判定した後関数を呼ぶ
            ResponseColisionIfDetected(hitObjectList[i], hitObjectList[j]);
        }
        //当たり判定情報を消すとき
        if (!hitObjectList[i]->isCollisionActive)
        {
            hitObjectList.erase(hitObjectList.begin() + i);
        }
    }
}

/// <summary>
/// 物体に当たったかを判定してその際の関数を呼ぶ
/// </summary>
/// <param name="collider">衝突を検出するオブジェクト</param>
/// <param name="target">衝突の対象になるオブジェクト</param>
void CollisionManager::ResponseColisionIfDetected(CollisionData* const & collider, CollisionData* const& target)
{
    switch (collider->hitObjectTag)
    {
    case Player:
        //エネミーと衝突した場合
        if (target->hitObjectTag == Boss)
        {
            //カプセル同士の当たり判定をおこなう
            if (IsHitCapsuleAndCapsule(*collider, *target))
            {
                //エネミーと当たった際の関数処理を呼ぶ
                collider->onHit(*target);
            }
        }
        break;
    case Boss:
        //エネミーと衝突した場合
        if (target->hitObjectTag == Player)
        {
            //カプセル同士の当たり判定をおこなう
            if (IsHitCapsuleAndCapsule(*collider, *target))
            {
                //エネミーと当たった際の関数処理を呼ぶ
                collider->onHit(*target);
            }
        }
        else if (target->hitObjectTag == PlayerAttack)
        {
            //カプセル同士の当たり判定をおこなう
            if (IsHitSphereAndCapsule(*target, *collider))
            {
                //エネミーと当たった際の関数処理を呼ぶ
                collider->onHit(*target);
            }
        }
        break;
    case PlayerAttack:
        //エネミーに攻撃がヒットした場合
        if (target->hitObjectTag == Boss)
        {
            //カプセルと球体の当たり判定を行う
            if (IsHitSphereAndCapsule(*collider, *target))
            {
                //エネミーと当たった際の関数処理を呼ぶ
                collider->onHit(*target);
            }
        }

    default:
        break;
    }

}


/// <summary>
/// 2つのベクトル間の距離を求める
/// </summary>
/// <param name="vector1">ベクトル１</param>
/// <param name="vector2">ベクトル２</param>
/// <returns>計算した距離</returns>
float CollisionManager::CalculationDistance(const VECTOR vector1, const VECTOR vector2)
{
    return sqrtf((vector1.x - vector2.x) * (vector1.x - vector2.x) +
        (vector1.y - vector2.y) * (vector1.y - vector2.y) +
        (vector1.z - vector2.z) * (vector1.z - vector2.z));
}


