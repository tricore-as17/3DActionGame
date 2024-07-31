#pragma once
#include"StateBase.h"

/// <summary>
/// ボスの静止ステート
/// </summary>
class BossIdle:public StateBase
{
public:
    //コンストラクタ
    BossIdle();
    //デストラクタ
    ~BossIdle();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="position">プレイヤーモデルの向き</param>
    void Update(VECTOR& modelDirection, VECTOR& position)override;

private:

};

