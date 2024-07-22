#pragma once

class ModelCollection;

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

    ModelCollection* modelCollection;   //モデルハンドルを格納しているクラスのポインタ
    int modelHandle;       //モデルハンドル

};


