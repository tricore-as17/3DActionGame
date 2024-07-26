#pragma once
#include"StateBase.h"


/// <summary>
/// プレイヤーの攻撃に関するステート
/// </summary>
class PlayerShotMagic :public StateBase
{
public:
    //コンストラクタ
    PlayerShotMagic(int modelHandle, int beforeAnimationIndex);
    //デストラクタ
    ~PlayerShotMagic();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="modelDirection">プレイヤーモデルの向き</param>
    void Update(VECTOR& modelDirection)override;

    /// <summary>
    /// ステートの切り替え処理をまとめたもの
    /// </summary>
    void ChangeState()override;

private:

};
