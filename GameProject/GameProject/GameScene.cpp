#include"DxLib.h"
#include "GameScene.h"
#include"GameOverScene.h"
#include"GameClearScene.h"
#include"Camera.h"
#include"Stage.h"
#include"Player.h"
#include"Boss.h"



/// <summary>
/// コンストラクタ
/// </summary>
GameScene::GameScene()
{
    //メモリの確保
    stage  = new Stage();
    camera = new Camera();
    player = new Player();
    boss   = new Boss();
}

/// <summary>
/// デストラクタ
/// </summary>
GameScene::~GameScene()
{
    //メモリの解放
    delete stage;
    delete camera;
    delete player;
    delete boss;
}

/// <summary>
/// 更新処理
/// </summary>
void GameScene::Update()
{

    player->Update();

    //デバッグ時だけキー入力でシーン遷移するように
#ifdef _DEBUG

    //Xキーが離されていればゲームクリアシーンに移行
    if (inputManager->GetKeyPushState(InputManager::X) == InputManager::JustRelease)
    {
        nextScene = new GameClearScene();
    }
    //Yキーが離されていればゲームオーバーシーンに以降
    else if (inputManager->GetKeyPushState(InputManager::Y) == InputManager::JustRelease)
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
    //各クラスの描画を行う
    stage->Draw();
    player->Draw();
    boss->Draw();
}
