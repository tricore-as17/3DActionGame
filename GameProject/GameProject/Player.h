#pragma once

class ModelDataManager;

class Player
{
public:
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



private:
    //定数
    static constexpr float DefaultScale = 0.015;   //通常の大きさ
    static constexpr float AdjustVelocityY = 0.01f;//y方向のvelocityを調整する際の大きさ

    int modelHandle;   //モデルハンドル
    VECTOR position;   //座標
    VECTOR direction;   //方向

    ModelDataManager* modelDataManager;

    /// <summary>
    /// 地面に向けたベクトルの調整
    /// </summary>
    /// <param name="velocity">プレイヤーのベロシティ</param>
    /// <returns>調整したベロシティ</returns>
    VECTOR AdjustGroundToWardVelocity(VECTOR velocity);
};
