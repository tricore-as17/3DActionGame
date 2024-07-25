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
    int modelHandle;   //モデルハンドル
    VECTOR position;   //座標
    VECTOR direction;  //方向


};
