#include"DxLib.h"
#include"Utility.h"


/// <summary>
/// 地面に向けたベクトルの調整
/// </summary>
/// <param name="velocity">プレイヤーのベロシティ</param>
/// <param name="beforePosition">反映させる前の座標</param>
/// <returns>調整したベロシティ</returns>
VECTOR Utility::AdjustGroundToWardVelocity(VECTOR velocity,VECTOR beforePosition)
{

    VECTOR adjustVelocity = velocity;
    //地面にめり込まなくなるまで戻す
    while (true)
    {
        //未来のY座標を出す
        float futureYPosition = beforePosition.y + adjustVelocity.y;
        //座標が0より下回っていたら修正する
        if (futureYPosition < 0)
        {
            adjustVelocity.y += AdjustVelocityY;
        }
        else
        {
            break;
        }

    }

    //調整した値を返す
    return adjustVelocity;
}

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
