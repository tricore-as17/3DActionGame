#pragma once
#include"StateBase.h"


/// <summary>
/// プレイヤーの回避に関するステート
/// </summary>
class PlayerRolling :public StateBase
{
public:
    //コンストラクタ
    PlayerRolling(int modelHandle, int beforeAnimationIndex);
    //デストラクタ
    ~PlayerRolling();

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

};
