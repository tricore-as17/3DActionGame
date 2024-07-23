#include"FrameRateController.h"
#include"DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
FrameRateController::FrameRateController()
    :startTime(GetNowCount())
    ,roopCount(0)
{
    //処理なし
}


/// <summary>
/// デストラクタ
/// </summary>
FrameRateController::~FrameRateController()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
void FrameRateController::Update()
{
    //1フレーム目なら
    if (roopCount == 0)
    {
        startTime = GetNowCount();
    }
    //60フレーム目なら
    if (roopCount == RoopCountLimit)
    {
        //現在の値を代入
        int tmp = GetNowCount();
        //ループカウントの初期化
        roopCount = 0;
        startTime = tmp;
    }
    roopCount++;
}

/// <summary>
/// 計算した値から設定したフレームレートになるように同期させる
/// </summary>
void FrameRateController::Sync()
{
    int tookTime = GetNowCount() - startTime;                   //現在のフレームの経過から1フレーム目で計算した値を引く
    int waitTime = roopCount * MilliSecond / AvarageFrameRate - tookTime;            //tookTimeの値が大きいと１フレーム辺りにかかる時間が長いので処理が遅いことになる

    if (waitTime > 0)
    {
        Sleep(waitTime);
    }
}
