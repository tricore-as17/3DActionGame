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



    //Xが離されたらゲームシーンに移行
    if (inputManager->GetKeyPushState(InputManager::X) == InputManager::JustRelease)
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
