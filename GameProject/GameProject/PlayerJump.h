#pragma once
#include"DxLib.h"
#include"StateBase.h"

/// <summary>
/// プレイヤーのジャンプ時のステート
/// </summary>
class PlayerJump:public StateBase
{
public:
    //定数
    static constexpr float Gravity = 0.04f;   //落下させるときの重力値


    //コンストラクタ
    PlayerJump(int initialModelHandle, int beforeAnimationIndex,VECTOR beforeVelocity);
    //デストラクタ
    ~PlayerJump();

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
    //定数
    static constexpr float JumpPower         = 0.3f;     //ジャンプ力
    static constexpr float AnimationStopLine = 0.7f;     //アニメーションを止める基準

    //ジャンプ中の状態
    enum JumpState
    {
        Ground  = 0,   //地面にいる状態
        Jump    = 1,   //ジャンプ中
        EndJump = 2    //ジャンプ終了
    };

    //メンバ変数
    float     falllSpeed;   //落下速度
    JumpState jumpState;    //ジャンプ中の状態


};
