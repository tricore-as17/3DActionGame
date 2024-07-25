#pragma once

/// <summary>
/// 複数のクラスで使用する関数をまとめたもの
/// </summary>
class Utility
{
public:

    /// <summary>
    /// 地面に向けたベクトルの調整
    /// </summary>
    /// <param name="velocity">プレイヤーのベロシティ</param>
    /// <param name="beforePosition">反映させる前の座標</param>
    /// <returns>調整したベロシティ</returns>
    static VECTOR AdjustGroundToWardVelocity(VECTOR velocity,VECTOR beforePosition);

    /// <summary>
    /// ビット同士の足し算
    /// </summary>
    /// <param name="bitAddend">足される側のビット</param>
    /// <param name="bitAdder">足す側のビット</param>
    /// <returns>ビットの足し算の結果</returns>
    static int AddBit(int bitAddend, int bitAdder);

private:
    //関数内で使用する定数
    static constexpr float AdjustVelocityY = 0.01f;//y方向のvelocityを調整する際の大きさ
};
