#include"DxLib.h"
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
    //既にインスタンスが確保されているかのチェック
    if (colisionManager != nullptr)
    {
        return;
    }

    //シングルトンの作成
    colisionManager = new ColisionManager();
}

/// <summary>
/// インスタンスの削除
/// </summary>
void ColisionManager::DeleteInstance()
{
    if (colisionManager)
    {
        delete colisionManager;
    }
    //シングルトンの作成
    colisionManager = nullptr;
}



/// <summary>
/// 球体とカプセルとの当たり判定
/// </summary>
/// <param name="sphere">球体の当たり判定に必要な情報</param>
/// <param name="capsule">カプセルの当たり判定に必要な情報</param>
/// <returns>当たっているか</returns>
bool ColisionManager::IsHitSphereAndCapsule(ColisionData sphere, ColisionData capsule)
{
    //ToDo
    //値を返さないとエラーが起きるためとりあえすfalseを返しています。
    //当たり判定実装時に処理を追加します。
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
/// 地面に向けたベクトルの調整
/// </summary>
/// <param name="velocity">プレイヤーのベロシティ</param>
/// <param name="beforePosition">反映させる前の座標</param>
/// <returns>調整したベロシティ</returns>
VECTOR ColisionManager::AdjustGroundToWardVelocity(VECTOR velocity, VECTOR beforePosition)
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
void ColisionManager::Update()
{

    //オブジェクトの数二つ分をまわす
    for (int i = 0; i < hitObjectList.size(); i++)
    {
        for (int j = 0; j < hitObjectList.size(); j++)
        {
            if (i != j)
            {

            }
        }
    }

}
