#pragma once
#include"CollisionManager.h"




/// <summary>
/// 当たり判定をする際に必要なデータ
/// </summary>
struct CollisionData
{
    /// <summary>
    /// 当たり判定の状態
    /// </summary>
    enum CollisionState
    {
        NoCollision     = 0, //当たり判定が無い
        CollisionActive = 1, //当たり判定がある
        CollisionEnded  = 2, //当たり判定が終了した
    };

    CollisionManager::HitObjectTag hitObjectTag;          //オブジェクトの種類
    VECTOR                         upPosition;            //カプセルを使用する場合の上側の座標
    VECTOR                         bottomPosition;        //カプセルを使用する場合の下側の座標
    VECTOR                         centerPosition;        //中心座標
    function<void(CollisionData)>  onHit;                 //当たった際の関数
    CollisionState                 collisionState;        //当たり判定の状態
    float                          radius;                //半径
    int                            damageAmount;          //与えるダメージ量

};
