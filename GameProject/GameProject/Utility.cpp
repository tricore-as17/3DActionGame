#include"DxLib.h"
#include"Utility.h"


/// <summary>
/// ビット同士の足し算
/// </summary>
/// <param name="bitAddend">足される側のビット</param>
/// <param name="bitAdder">足す側のビット</param>
/// <returns>ビットの足し算の結果</returns>
int Utility::AddBit(int bitAddend, int bitAdder)
{
    while (bitAdder != 0)
    {
        // キャリーを計算
        int carry = bitAddend & bitAdder;

        // XOR演算でキャリーなしの加算を行う
        bitAddend = bitAddend ^ bitAdder;

        // キャリーを左にシフトして次の桁に移動
        bitAdder = carry << 1;
    }
    return bitAddend;
}

