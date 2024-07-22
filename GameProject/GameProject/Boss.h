#pragma once


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
    //メンバ変数
    VECTOR position;       //座標

};
