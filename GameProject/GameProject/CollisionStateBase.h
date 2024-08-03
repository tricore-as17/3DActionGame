#pragma once


struct CollisionData;
class  CollisionManager;

/// <summary>
/// 当たり判定を作成ステートが使用するクラス
/// </summary>
class CollisionStateBase abstract
{
public:

    //////  enum  ///////

    /// <summary>
    /// コンストラクタ
    /// </summary>
    CollisionStateBase();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CollisionStateBase();

    //////  メンバ関数  //////

    /// <summary>
    /// 座標などを当たり判定に必要なデータに変換
    /// </summary>
    virtual void UpdateCollisionData(const VECTOR& modelDirection, const VECTOR characterPosition) abstract;

    /// <summary>
    /// アニメーションの再生時間に合わせて当たり判定情報を渡す
    /// </summary>
    void SendCollisionDataByAnimationTime(float animationNowTime, float animationLimitTime);


protected:
    ///////  メンバ変数  ////////

    VECTOR            position;                      //攻撃の当たり判定の座標
    VECTOR            offsetPosition;                //キャラクターの座標からどの程度動かすか
    float             offsetPositionScale;           //キャラクターからどれだけの距離離すか
    float             collisionStratAnimationRatio;  //当たり判定を始めるアニメーションの再生率
    CollisionData     collisionData;                 //当たり判定に必要な情報をまとめたもの
    CollisionManager* collisionManager;              //当たり判定の管理クラスのポインタ

    ///////  メンバ関数  ///////

    /// <summary>
    /// キャラクターの座標から当たり判定を生成する場所を設定する
    /// </summary>
    /// <param name="characterPosition">キャラの座標</param>
    /// <param name="direction">生成する方向</param>
    void TransrateCollisionCapsulePosition(VECTOR characterPosition, VECTOR direction);

    /// <summary>
    /// カプセルの回転させるベクトルの計算
    /// </summary>
    /// <param name="radian">ラジアン</param>
    /// <param name="objectPosition">カプセルの座標</param>
    /// <param name="capsuleLineLength">カプセルの線分の長さ</param>
    /// <returns>計算したベクトル</returns>
    VECTOR RotationCollisionCapsule(float radian, VECTOR modelDirection, VECTOR position, float capsuleLineLength);

private:


};


