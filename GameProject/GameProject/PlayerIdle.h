#pragma once
#include"StateBase.h"
#include"InputManager.h"

/// <summary>
/// プレイヤーの待機状態ステート
/// </summary>
class PlayerIdle :public StateBase
{
public:
    //コンストラクタ
    PlayerIdle(int& modelHandle, const int beforeAnimationIndex);
    //デストラクタ
    ~PlayerIdle();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="position">プレイヤーモデルの向き</param>
    void Update(VECTOR& modelDirection, VECTOR& position)override;


private:
    static constexpr float InitialAnimationSpeed = 1.0f;    
    
    /// <summary>
    /// ステートの切り替え処理をまとめたもの
    /// </summary>
    void ChangeState()override;


    //メンバ変数
    InputManager* inputManager;    //インプットマネージャーにアクセスするためのポインタ
    int           keyInput;        //キーの入力状態
    bool          isGround;        //接地しているか

};
