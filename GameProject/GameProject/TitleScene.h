#pragma once
#include"SceneBase.h"


/// <summary>
/// タイトル用のシーン
/// </summary>
class TitleScene:public SceneBase
{
public:
    //コンストラクタ
    TitleScene();
    //デストラクタo
    ~TitleScene();
    /// <summary>
    /// 更新処理
    /// </summary>
    void Update() override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;
private:

};
