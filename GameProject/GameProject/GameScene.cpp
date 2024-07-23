#include"DxLib.h"
#include "GameScene.h"
#include"GameOverScene.h"
#include"GameClearScene.h"


/// <summary>
/// コンストラクタ
/// </summary>
GameScene::GameScene()
{
    //処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
GameScene::~GameScene()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
void GameScene::Update()
{

    //デバッグ時だけキー入力でシーン遷移するように
#ifdef _DEBUG
    //左矢印キーが一度押された後離されたかのチェック
    bool leftKeyRelease = inputManager->IsReleaseKey(PAD_INPUT_LEFT);
    //右矢印キーが一度押された後離されたかのチェック
    bool rightKeyRelease = inputManager->IsReleaseKey(PAD_INPUT_RIGHT);

    //左矢印キーが離されていればゲームクリアシーンに移行
    if (leftKeyRelease)
    {
        nextScene = new GameClearScene();
    }
    //右矢印キーが離されていればゲームオーバーシーンに以降
    else if (rightKeyRelease)
    {
        nextScene = new GameOverScene();
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
void GameScene::Draw()
{
#ifdef _DEBUG
    DrawString(500, 500, "ゲームシーン", GetColor(255, 255, 255));
#endif
}
