﻿#pragma once
#include"DxLib.h"
#include"CollisionData.h"

class CollisionManager;
struct InitializeShotData;

/// <summary>
/// 弾クラス
/// </summary>
class Shot
{
public:

    ///////  ゲッター  ///////

    const bool GetIsActive() const { return isActive; }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Shot();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Shot();

    /// <summary>
    /// 弾の初期化
    /// </summary>
    /// <param name="initializeShotData">初期化用のデータ構造</param>
    void Initialize(InitializeShotData initializeShotData);

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    /// <summary>
    /// 当たった時の処理
    /// </summary>
    void OnHit(CollisionData collisionData);

    /// <summary>
    /// 座標などを当たり判定に必要なデータに変換
    /// </summary>
    void UpdateCollisionData() ;



private:

    //////  メンバ変数  ///////

    // 基本情報
    VECTOR                         position;             // ショットの座標
    VECTOR                         direction;            // 進む方向
    float                          speed;                // スピード
    float                          radius;               // 半径
    int                            damageAmount;         // ショットのダメージ
    bool                           isActive;             // 弾が有効な状態か
    CollisionManager::HitObjectTag shooterTag;           // 弾を撃ったキャラの種類 
    // 当たり判定
    CollisionManager* collisionManager;     // 当たり判定を管理するクラスにアクセスするポインタ
    CollisionData     collisionData;        // 当たり判定情報を格納するためのデータ構造


};
