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
    //右矢印キーが押されたかのチェック
    bool isLeftKeyRelease = inputManager->IsReleaseKey(PAD_INPUT_LEFT);
    //右矢印キーが押されていればゲームオーバーシーンに以降
    bool isRightKeyRelease = inputManager->IsReleaseKey(PAD_INPUT_RIGHT);

    //左矢印キーが押されていればゲームクリアシーンに以降
    if (isLeftKeyRelease)
    {
        inputScene = new GameClearScene();
    }
    else if (isRightKeyRelease)
    {
        inputScene = new GameOverScene();
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
void GameScene::Draw()
{
#ifdef _DEBUG
    DrawString(500, 500, "ゲームシーン", GetColor(255, 255, 255));
#endif
}
