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
    //スペースキーが押されたかのチェック
    bool isKeyRelease = inputManager->IsReleaseKey(PAD_INPUT_10);

    //スペースキーが押されていればゲームシーンに移行
    if (isKeyRelease)
    {
        inputScene = new GameScene();
    }
    else
    {
        inputScene = this;
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
