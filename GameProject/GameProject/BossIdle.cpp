#include"BossIdle.h"
#include"Boss.h"
#include"StateBase.h"


///<summary>
///コンストラクタ
///</summary>
BossIdle::BossIdle(int& InitializeModelHandle,const int beforeAnimationIndex)
    :StateBase(InitializeModelHandle,Boss::Idle,beforeAnimationIndex)
{


}

/// <summary>
/// デストラクタ
/// </summary>
BossIdle::~BossIdle()
{

}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void BossIdle::Update(VECTOR& modelDirection, VECTOR& position)
{

}
