#pragma once
#include<vector>
#include"StateBase.h"
#include"InputManager.h"

//プロトタイプ宣言
class InputManager;

/// <summary>
/// プレイヤーの移動に関するステート
/// </summary>
class PlayerMove:public StateBase
{
public:
    //コンストラクタ
    PlayerMove(int modelHandle, int beforeAnimationIndex);
    //デストラクタ
    ~PlayerMove();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="position">プレイヤーモデルの向き</param>
    void Update(VECTOR& modelDirection)override;

    /// <summary>
    /// ステートの切り替え処理をまとめたもの
    /// </summary>
    void ChangeState()override;
private:
    static constexpr float MoveSpeed = 1.3f;   //移動量
    /// <summary>
    /// 移動方向の選択
    /// </summary>
    VECTOR DecisionDirection();
    //メンバ変数
    InputManager* inputManager;              //インプットマネージャーにアクセスするためのポインタ
};
