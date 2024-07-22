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
    /// 移動に関する処理
    /// </summary>
    void Move();



    /// <summary>
    /// 描画
    /// </summary>
    void Draw();



private:
    int modelHandle;   //モデルハンドル
    VECTOR position;   //座標
    VECTOR direction;   //方向

    ModelCollection* modelCollection;
};
