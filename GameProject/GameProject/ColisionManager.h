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
        Player       = 0,    //プレイヤー
        Enemy        = 1,    //エネミー
        PlayerAttack = 2,    //プレイヤーの攻撃
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
    bool IsHitSphereAndCapsule(ColisionData sphere, ColisionData capsule);

    /// <summary>
    /// 当たったあとの処理を持ってくる
    /// </summary>
    /// <param name="colisionData">当たり判定に必要な情報</param>
    /// <param name="hitObjectTag">オブジェクトの種類</param>
    /// <param name="onHit">当たった後に行う関数のポインタ</param>
    static void Resister(ColisionData colisionData, HitObjectTag hitObjectTag
        , function<void(ColisionData, HitObjectTag)> onHit);

    /// <summary>
    /// 地面に向けたベクトルの調整
    /// </summary>
    /// <param name="velocity">プレイヤーのベロシティ</param>
    /// <param name="beforePosition">反映させる前の座標</param>
    /// <returns>調整したベロシティ</returns>
    static VECTOR AdjustGroundToWardVelocity(VECTOR velocity, VECTOR beforePosition);

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

private:
    //関数内で使用する定数
    static constexpr float AdjustVelocityY = 0.01f;//y方向のvelocityを調整する際の大きさ

    //自身のポインタ
    static ColisionManager* colisionManager;

    //当たり判定情報をもったリスト
    map<HitObjectTag, ColisionData> hitObjectList;

    //コンストラクタ
    ColisionManager();

    //デストラクタ
    ~ColisionManager();

    void 

};

