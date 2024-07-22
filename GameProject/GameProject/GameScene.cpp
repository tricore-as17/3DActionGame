#include"DxLib.h"
#include "GameScene.h"
#include"GameOverScene.h"
#include"GameClearScene.h"
#include"Stage.h"


/// <summary>
/// コンストラクタ
/// </summary>
GameScene::GameScene()
{
    //メモリの確保
    stage = new Stage();
}

/// <summary>
/// デストラクタ
/// </summary>
GameScene::~GameScene()
{
    //メモリの解放
    delete stage;
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
    //各クラスの描画を行う
    stage->Draw();
}
