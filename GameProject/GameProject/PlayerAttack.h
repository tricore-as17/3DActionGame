#pragma once
#include"StateBase.h"


/// <summary>
/// プレイヤーの攻撃に関するステート
/// </summary>
class PlayerAttack :public StateBase
{
public:
    //コンストラクタ
    PlayerAttack(int modelHandle, int beforeAnimationIndex,Player::AnimationState animationState);
    //デストラクタ
    ~PlayerAttack();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="modelDirection">プレイヤーモデルの向き</param>
    void Update(VECTOR& modelDirection, VECTOR& position)override;

    /// <summary>
    /// ステートの切り替え処理をまとめたもの
    /// </summary>
    void ChangeState()override;



private:
    static constexpr float  CollisionCapsuleLineHalfLength = 10.0f;    //当たり判定のカプセルの半分の長さ
    static constexpr float  CollisionRadius                = 7.0f;     //当たり判定のカプセルの半径
    static const     VECTOR OffsetPositionY;                           //プレイヤーと攻撃の当たり判定座標がどれだけずれているか
    static constexpr float  OffsetPositionScale            = 18.0f;    //プレイヤーとどれだけ離すかの大きさ 

    VECTOR position;       //攻撃の当たり判定の座標
    bool   isHited;        //攻撃が当たったか



    //攻撃した時の当たり判定に必要な情報をまとめたもの
    CollisionData collisionData;           //当たり判定に必要な情報をまとめたもの
    int registerTag;                       //レジスタの識別番号
    CollisionManager* collisionManager;    //当たり判定の管理クラスのポインタ



    /// <summary>
    /// 座標などを当たり判定に必要なデータに変換
    /// </summary>
    void ConvertCollisionData();

    /// <summary>
    /// コリジョンマネージャーにレジスタを渡す
    /// </summary>
    void SendRegister();

    /// <summary>
    /// 当たった時の処理
    /// </summary>
    void OnHit(CollisionData collisionData);

#ifdef _DEBUG
    /// <summary>
    /// 当たり判定を描画する(デバッグ用)
    /// </summary>
    void DrawCollision() override;
#endif 




};
