#pragma once

class ModelDataManager;


/// <summary>
/// ボスのクラス
/// </summary>
class Boss
{
public:
    //コンストラクタ
    Boss();
    //デストラクタ
    ~Boss();

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
    static constexpr float DefaultScale = 0.002;     //モデルの初期サイズ

    //メンバ変数
    int modelHandle;        //モデルハンドル
    VECTOR position;       //座標
    ModelDataManager* modelDataManager; //モデルハンドルをもっているクラスのポインタ

};
