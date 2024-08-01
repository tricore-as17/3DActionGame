﻿#pragma once
#include"StateBase.h"
#include"InputManager.h"

/// <summary>
/// ボスの通常攻撃のステート
/// </summary>
class BossDefaultAttack :public StateBase
{
public:
    //コンストラクタ
    BossDefaultAttack(int& InitializeModelHandle, const int beforeAnimationIndex);
    //デストラクタ
    ~BossDefaultAttack();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="position">プレイヤーモデルの向き</param>
    void Update(VECTOR& modelDirection, VECTOR& position)override;

    /// <summary>
    /// ステートの切り替え処理をまとめたもの
    /// </summary>
    void ChangeState()override;

private:
    //定数
    static constexpr float InitializeAnimationSpeed = 0.5f;   //アニメーション速度

    //ToDo
    //AIを作成したら入力は必要ないので削除
    InputManager* inputManager;      //入力管理クラス
};

