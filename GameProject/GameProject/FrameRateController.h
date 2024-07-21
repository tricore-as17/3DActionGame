#pragma once

/// <summary>
/// フレームレートを調節するクラス
/// </summary>
class FrameRateController
{
public:
    //コンストラクタ
    FrameRateController();
    //デストラクタ
    ~FrameRateController();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 計算した値から設定したフレームレートになるように同期させる
    /// </summary>
    void Sync();
private:
    static constexpr int RoopCountLimit = 60;   //ループカウントの上限
    static constexpr int MilliSecond  = 1000;   //ミリ秒に変換する時に掛ける値
    static constexpr int AvarageFrameRate = 60; //目標フレームレート

    int startTime;        //ループ開始時の時間
    int roopCount;        //ループの回数
};
