#pragma once
#include"DxLib.h"

//クラスのプロトタイプ宣言
class ModelDataManager;
class StateBase;

class Player
{
public:

    //アニメーションの種類
    enum AnimationState
    {
        Turn180        = 0,
        BackWalk       = 1,
        Block          = 2,
        BlockingImpact = 3,
        Clash          = 4,
        Death          = 5,
        Impact         = 6,
        Idle           = 7,
        Jump           = 8,
        LeftTurn       = 9,
        LeftWalk       = 10,
        RightTurn      = 11,
        RightWalk      = 12,
        Rolling        = 13,
        Run            = 14,
        Slash          = 15,
        StartBlocking  = 16,
        Walk           = 17,
        Spell          = 18
    };
    //コンストラクタ
    Player();
    //デストラクタ
    virtual ~Player();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    /// <summary>
    /// プレイヤーの回転制御
    /// </summary>
    /// <param name="direction">プレイヤーの移動方向</param>
    void UpdateAngle();



private:
    //定数
    static constexpr float AngleSpeed = 0.15f;      //モデルの向きを変えるスピード

    //メンバ変数
    int modelHandle;       //モデルハンドル
    VECTOR position;       //座標
    float angle;           //モデルの向いている角度
    VECTOR modelDirection; //モデルの向くべき方向
    //メンバクラス
    ModelDataManager* modelDataManager;
    StateBase* nowState;                            //現在のステートを保存するポインタ
    StateBase* nextState;                           //次のループでのステートを保存するポインタ


    //関数

    /// <summary>
    /// ステートの移行処理
    /// </summary>
    void ChangeState();
    

};
