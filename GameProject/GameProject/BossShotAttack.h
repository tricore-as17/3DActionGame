﻿#pragma once
#include"StateBase.h"
#include"InputManager.h"
#include"ShotManager.h"

struct InitializeShotData;

/// <summary>
/// ボスの静止ステート
/// </summary>
class BossShotAttack :public StateBase
{
public:

    ///////  メンバ関数  //////

    //コンストラクタ
    BossShotAttack(int& modelHandle, const int beforeAnimationIndex);
    //デストラクタ
    ~BossShotAttack();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="position">プレイヤーモデルの向き</param>
    void Update(VECTOR& modelDirection, VECTOR& position,const VECTOR targetPosition)override;

private:

    ///////  enum  ///////

    /// <summary>
    /// 弾を撃っている状態
    /// </summary>
    enum ShotState
    {
        WaitLeftShot  = 0,   // レフトショット待機
        LeftShot      = 1,   // レフトショットを撃った後
        WaitRightShot = 2,   // ライトショット待機
        RightSHot     = 3,   // ライトショットを撃った後
    };

    ///////  定数  ///////

    static constexpr float InitializeAnimationSpeed = 0.5f;    //アニメーションの初期速度
    static constexpr float ShotCreateAnimationRatio = 0.35f;   // ショットを作成するアニメーションの再生率
    static constexpr float ShotSpeed                = 6.0f;    // 弾のスピード
    static constexpr float ShotRadius               = 20.0f;   // 弾の半径
    static constexpr int   ShotDamageAmount         = 1;       // ショットが与えるダメージ
    

    ///////  メンバ変数  ////////

    //ToDo
    //AIを作成したら入力は必要ないので削除
    InputManager* inputManager;      //入力管理クラス

    ShotManager* shotManager;        // ショット管理クラスのポインタ
    bool         isAnimationSwitch;  // アニメーションを切り替えたかのフラグ
    ShotState    shotState;          // 弾の撃っている状態

    ///////  メンバ関数  //////

    /// <summary>
    /// ステートの切り替え処理をまとめたもの
    /// </summary>
    void ChangeState()override;

    /// <summary>
    /// アニメーションの切り替え
    /// </summary>
    void SwitchAnimation();

    /// <summary>
    /// アニメーションの再生率によってショットを作成
    /// </summary>
    /// <param name="position">自身の座標</param>
    void CreateShotByAnimationTime(const VECTOR position, const VECTOR targetPosition);

    /// <summary>
    /// 弾の作成に必要な情報を
    /// </summary>
    InitializeShotData AssignInitializeShotData(const VECTOR position,const VECTOR targetPosition);
};
