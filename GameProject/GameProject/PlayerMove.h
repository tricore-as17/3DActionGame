﻿#pragma once
#include<vector>
#include"StateBase.h"
#include"InputManager.h"

//プロトタイプ宣言
class InputManager;

/// <summary>
/// プレイヤーの移動に関するステート
/// </summary>
class PlayerMove:public StateBase
{
public:
    //コンストラクタ
    PlayerMove(int modelHandle, int beforeAnimationIndex);
    //デストラクタ
    ~PlayerMove();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="position">自身のモデルの向き</param>
    /// <param name="position">自身のキャラクターの座標</param>
    /// <param name="targetPosition">敵対しているキャラの座標</param>
    void Update(VECTOR& modelDirection, VECTOR& position,const VECTOR targetPosition,VECTOR cameraPosition)override;

    /// <summary>
    /// ステートの切り替え処理をまとめたもの
    /// </summary>
    void ChangeState()override;
private:
    static constexpr float MoveSpeed = 1.3f;   //移動量


    /// <summary>
    /// 移動方向の設定
    /// </summary>
    /// <param name="cameraPosition">カメラの座標</param>
    /// <param name="characterPosition">自身の座標</param>
    /// <returns>設定された座標</returns>
    VECTOR DecisionDirection(const VECTOR cameraPosition, const VECTOR characterPosition);

    ///////  メンバ変数  ///////

    InputManager* inputManager;              //インプットマネージャーにアクセスするためのポインタ

    bool isGround;                           //接地しているか

};
