#pragma once

/// <summary>
/// 複数のクラスで使用する関数をまとめたもの
/// </summary>
class Utility
{
public:

    /// <summary>
    /// ビット同士の足し算
    /// </summary>
    /// <param name="bitAddend">足される側のビット</param>
    /// <param name="bitAdder">足す側のビット</param>
    /// <returns>ビットの足し算の結果</returns>
    static int AddBit(int bitAddend, int bitAdder);

    static constexpr float ErrorValue = 0.000001f;  //float型で許容する誤差の値

};
