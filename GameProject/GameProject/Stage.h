#pragma once

class ModelDataManager;

class Stage
{
public:
    //コンストラクタ
    Stage();
    //デストラクタ
    ~Stage();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

private:
    //定数
    static const VECTOR InitialPosition;  //初期座標
    static constexpr float DefaultScale = 0.002;

    ModelDataManager* modelDataManager;   //モデルハンドルを格納しているクラスのポインタ
    int modelHandle;       //モデルハンドル

};


