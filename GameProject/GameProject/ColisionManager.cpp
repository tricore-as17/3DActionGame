#include "ColisionManager.h"
#include"ColisionData.h"

/// <summary>
/// コンストラクタ
/// </summary>
ColisionManager::ColisionManager()
{

}

/// <summary>
/// デストラクタ
/// </summary>
ColisionManager::~ColisionManager()
{

}

/// <summary>
/// インスタンスを作成する
/// </summary>
void ColisionManager::CreateInstance()
{

}

/// <summary>
/// インスタンスの削除
/// </summary>
void ColisionManager::DeleteInstance()
{

}



/// <summary>
/// 球体とカプセルとの当たり判定
/// </summary>
/// <param name="sphere">球体の当たり判定に必要な情報</param>
/// <param name="capsule">カプセルの当たり判定に必要な情報</param>
/// <returns>当たっているか</returns>
bool ColisionManager::IsHitSphereAndCapsule(ColisionData sphere, ColisionData capsule)
{
    bool isHit = false;

    return isHit;
}

/// <summary>
/// 当たったあとの処理を持ってくる
/// </summary>
/// <param name="colisionData">当たり判定に必要な情報</param>
/// <param name="hitObjectTag">オブジェクトの種類</param>
/// <param name="onHit">当たった後に行う関数のポインタ</param>
void ColisionManager::Resister(ColisionData colisionData, HitObjectTag hitObjectTag
    , function<void(ColisionData, HitObjectTag)> onHit)
{

}


/// <summary>
/// 更新処理
/// </summary>
void ColisionManager::Update()
{

}
