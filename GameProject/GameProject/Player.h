#pragma once

class ModelCollection;

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

    int modelHandle;   //モデルハンドル
    VECTOR position;   //座標
    VECTOR direction;   //方向

    ModelCollection* modelCollection;
};
