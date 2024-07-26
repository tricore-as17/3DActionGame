#include"DxLib.h"
#include "GameClearScene.h"
#include"TitleScene.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameClearScene::GameClearScene()
{
    //処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
GameClearScene::~GameClearScene()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
void GameClearScene::Update()
{
    //デバッグ時だけキー入力でシーン遷移するように
#ifdef _DEBUG

    //Xキーが離された瞬間ならタイトルシーンに以降
    if (inputManager->GetKeyPushState(InputManager::X) == InputManager::JustRelease)
    {
        nextScene = new TitleScene();
    }
    else
    {
        nextScene = this;
    }
#endif
}

/// <summary>
/// 描画
/// </summary>
void GameClearScene::Draw()
{
#ifdef _DEBUG
    DrawString(500, 500, "クリアシーン", GetColor(255, 255, 255));
#endif

}


