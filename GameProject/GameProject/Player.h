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
        Turn180        = 0,    //180度回転
        BackWalk       = 1,    //後ろ歩き
        Block          = 2,    //ガード
        BlockingImpact = 3,    //ガード中にダメージを受ける
        Clash          = 4,    //強攻撃
        Death          = 5,    //死亡
        Impact         = 6,    //ダメージヒット
        Idle           = 7,    //静止
        Jump           = 8,    //ジャンプ
        LeftTurn       = 9,    //左回転
        LeftWalk       = 10,   //左歩き
        RightTurn      = 11,   //右回転
        RightWalk      = 12,   //右歩き
        Rolling        = 13,   //回避
        Run            = 14,   //走り
        Slash          = 15,   //通常攻撃
        StartBlocking  = 16,   //防御開始
        Walk           = 17,   //歩き
        Spell          = 18    //魔法攻撃
    };

    //getter,setter
    const VECTOR GetPosition()const { return position; }

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
    StateBase* nowState;                            //現在のステートを保存するポインタ
    StateBase* nextState;                           //次のループでのステートを保存するポインタ


    //メンバ関数

    /// <summary>
    /// ステートの移行処理
    /// </summary>
    void ChangeState();
    

};
