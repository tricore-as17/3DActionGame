#pragma once
#include"DxLib.h"
#include"Player.h"



/// <summary>
/// ステート管理に使用する基底クラス
/// </summary>
class StateBase
{
public:
    //コンストラクタ
    StateBase(int& modelHandle, Player::AnimationState animationState, const int beforeAnimationIndex);
    //デストラクタ
    virtual ~StateBase();

    /// <summary>
    /// 次のステートを返す
    /// </summary>
    /// <returns>次のステート</returns>
    StateBase* GetNextState() { return nextState; }

    /// <summary>
    /// 更新処理
    /// </summary>
    virtual void Update(VECTOR& modelDirection,VECTOR& position)abstract;

    /// <summary>
    /// 移動処理などが終わった後のベロシティを渡す
    /// </summary>
    /// <returns></returns>
    const VECTOR GetVelocity() const { return velocity; }

protected:
    //アニメーションの再生状態
    enum AnimationPlayState
    {
        BlendStart   = 0,    //前のアニメーションとのブレンドを開始
        BlendEnd     = 1,    //前のアニメーションとのブレンドの終了
        FirstRoop    = 2,    //ファーストループの再生中
        FirstRoopEnd = 3,    //ファーストループの再生終了
        Stop         = 4,    //停止中
    };

    int modelhandle;              //ステートで使用するモデルハンドル
    StateBase* nextState;         //次のループでのステートを代入する用の変数
    float animationLimitTime;     //再生中のアニメーションの総再生時間
    float animationNowTime;       //再生中のアニメーションの現在の経過時間
    float animationSpeed;         //派生クラスで代入する
    int   animationIndex;         //現在のアニメーションのインデックス
    int   beforeAnimationIndex;   //前回のアニメーションのインデックス
    float animationBlendRate;     //前回のアニメーションと現在のアニメーションでのブレンド率
    VECTOR velocity;              //速度やベクトルを含んだ値

    AnimationPlayState currentPlayAnimationState;     //アニメーションの再生状態


    /// <summary>
    /// ステートの切り替え処理をまとめたもの
    /// </summary>
    virtual void ChangeState()abstract;

    /// <summary>
    /// アニメーションの更新処理
    /// </summary>
    void UpdateAnimation();

    /// <summary>
    /// アニメーションを止める処理
    /// </summary>
    void StopAnimation();

    /// <summary>
    /// アニメーションを開始させる処理
    /// </summary>
    void StartAnimation();



};
