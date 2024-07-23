#include"DxLib.h"
#include"TitleScene.h"
#include"GameScene.h"


/// <summary>
/// コンストラクタ
/// </summary>
TitleScene::TitleScene()
{
    //処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
TitleScene::~TitleScene()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
void TitleScene::Update()
{
    //スペースキーが離されたかのチェック
    bool keyRelease = inputManager->IsReleaseKey(PAD_INPUT_10);

    //スペースキーが離されたらゲームシーンに移行
    if (keyRelease)
    {
        nextScene = new GameScene();
    }
    else
    {
        nextScene = this;
    }
}


/// <summary>
/// 描画
/// </summary>
void TitleScene::Draw()
{
#ifdef _DEBUG
    DrawString(500, 500, "タイトルシーン", GetColor(255, 255, 255));
#endif
}
