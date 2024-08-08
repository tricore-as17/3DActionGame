#pragma once
#include"CollisionData.h"

class CollisionUtility
{
public:

    /// <summary>
    /// アニメーションの再生時間に合わせて当たり判定情報を渡す
    /// </summary>
    /// <param name="animationNowTime">現在のアニメーションの再生率</param>
    /// <param name="animationLimitTime">アニメーションの総再生時間</param>
    static CollisionData::CollisionState SendCollisionDataByAnimationTime(float animationNowTime, float animationLimitTime,
        CollisionData::CollisionState currentCollisionState, float collisionStartAnimationRatio);

    /// <summary>
    /// キャラクターの座標から当たり判定を生成する場所を設定する
    /// </summary>
    /// <param name="characterPosition"></param>
    /// <param name="direction"></param>
    /// <returns></returns>
    static VECTOR TransrateCollisionCapsulePosition(VECTOR characterPosition, VECTOR direction,VECTOR offsetPosition,float offsetPositionScale);


    /// <summary>
    /// カプセルの回転させるベクトルの計算
    /// </summary>
    /// <param name="radian">ラジアン</param>
    /// <returns>計算したベクトル</returns>
    static VECTOR RotationCollisionCapsule(float radian, VECTOR modelDirection, VECTOR position, float capsuleLineLength);
};
