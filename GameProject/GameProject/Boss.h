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
    static const VECTOR InitialPosition;             //初期座標

    //メンバ変数
    int modelHandle;        //モデルハンドル
    VECTOR position;       //座標
    ModelDataManager* modelDataManager; //モデルハンドルをもっているクラスのポインタ

};
