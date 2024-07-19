#pragma once
#include<map>
#include<functional>
using namespace std;

struct ColisionData;

/// <summary>
/// 当たり判定を見るクラス
/// </summary>
class ColisionManager
{
public:
    /// <summary>
    /// 当たり判定を見るオブジェクトの種類
    /// </summary>
    enum HitObjectTag
    {

    };

    //インスタンスを取得するゲッター
    static ColisionManager* GetInstance() { return colisionManager; }
    //インスタンスを作成する
    static void CreateInstance();

    /// <summary>
    /// インスタンスの削除
    /// </summary>
    static void DeleteInstance();

    /// <summary>
    /// 球体とカプセルとの当たり判定
    /// </summary>
    /// <param name="sphere">球体の当たり判定に必要な情報</param>
    /// <param name="capsule">カプセルの当たり判定に必要な情報</param>
    /// <returns>当たっているか</returns>
    static bool IsHitSphereAndCapsule(ColisionData sphere, ColisionData capsule);

    /// <summary>
    /// 当たったあとの処理を持ってくる
    /// </summary>
    /// <param name="colisionData">当たり判定に必要な情報</param>
    /// <param name="hitObjectTag">オブジェクトの種類</param>
    /// <param name="onHit">当たった後に行う関数のポインタ</param>
    static void Resister(ColisionData colisionData, HitObjectTag hitObjectTag
        , function<void(ColisionData, HitObjectTag)> onHit);

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

private:

    //自身のポインタ
    static ColisionManager* colisionManager;

    //当たり判定情報をもったリスト
    map<HitObjectTag, ColisionData> hitObjectList;

    //コンストラクタ
    ColisionManager();

    //デストラクタ
    ~ColisionManager();

};

