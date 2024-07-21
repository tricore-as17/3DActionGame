#include"DxLib.h"
#include "GameOverScene.h"
#include"GameScene.h"
#include"TitleScene.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameOverScene::GameOverScene()
{
    //処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
GameOverScene::~GameOverScene()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
void GameOverScene::Update()
{

    //デバッグ時だけキー入力でシーン遷移するように
#ifdef _DEBUG
    //右矢印キーが押されたかのチェック
    bool isLeftKeyRelease = inputManager->IsReleaseKey(PAD_INPUT_LEFT);
    //右矢印キーが押されていればゲームオーバーシーンに以降
    bool isRightKeyRelease = inputManager->IsReleaseKey(PAD_INPUT_RIGHT);

    //左矢印キーが押されていればゲームシーンに移行
    if (isLeftKeyRelease)
    {
        inputScene = new GameScene();
    }
    else if (isRightKeyRelease)
    {
        inputScene = new TitleScene();
    }
    else
    {
        inputScene = this;
    }
#endif
}

/// <summary>
/// 描画
/// </summary>
void GameOverScene::Draw()
{
#ifdef _DEBUG
    DrawString(500, 500, "ゲームオーバーシーン", GetColor(255, 255, 255));
#endif
}
