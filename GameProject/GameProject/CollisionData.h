#pragma once
#include"CollisionManager.h"




/// <summary>
/// 当たり判定をする際に必要なデータ
/// </summary>
struct CollisionData
{
    CollisionManager::HitObjectTag hitObjectTag;   //オブジェクトの種類
    VECTOR upPosition;                             //カプセルを使用する場合の上側の座標
    VECTOR bottomPosition;                         //カプセルを使用する場合の下側の座標
    VECTOR centerPosition;                         //中心座標
    function<void(CollisionData)> onHit;           //当たった際の関数
    float radius;                                  //半径

};
