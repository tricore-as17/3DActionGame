#pragma once
#include"StateBase.h"
#include"InputManager.h"

/// <summary>
/// ボスの通常攻撃のステート
/// </summary>
class BossDefaultAttack :public StateBase
{
public:
    //コンストラクタ
    BossDefaultAttack(int& InitializeModelHandle, const int beforeAnimationIndex);
    //デストラクタ
    ~BossDefaultAttack();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="position">プレイヤーモデルの向き</param>
    void Update(VECTOR& modelDirection, VECTOR& position)override;


private:

    ///////  定数  ///////

    
    static constexpr float InitializeAnimationSpeed = 0.5f;   //アニメーション速度
    static constexpr 

    ///////  メンバ変数  ////////

    //ToDo
    //AIを作成したら入力は必要ないので削除
    InputManager* inputManager;      //入力管理クラス

    //攻撃した時の当たり判定に必要な情報をまとめたもの
    CollisionData     collisionData;       //当たり判定に必要な情報をまとめたもの
    CollisionManager* collisionManager;    //当たり判定の管理クラスのポインタ
    VECTOR            position;            //当たり判定の座標
    bool              isHited;             //攻撃が当たったか

    ///////  メンバ関数  //////

    /// <summary>
    /// ステートの切り替え処理をまとめたもの
    /// </summary>
    void ChangeState()override;

    /// <summary>
    /// 座標などを当たり判定に必要なデータに変換
    /// </summary>
    void UpdateCollisionData();

    /// <summary>
    /// 当たった時の処理
    /// </summary>
    void OnHit(CollisionData collisionData);
};

