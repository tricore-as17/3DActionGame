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
    //各クラスのアップデートを呼ぶ
    player->Update();
    camera->Update(player->GetPosition());


    //デバッグ時だけキー入力でシーン遷移するように
#ifdef _DEBUG
    //左矢印キーが一度押された後離されたかのチェック
    InputManager::KeyPushState leftKeyPushState = inputManager->GetKeyPushState(PAD_INPUT_9);
    //右矢印キーが一度押された後離されたかのチェック
    InputManager::KeyPushState rightKeyPushState = inputManager->GetKeyPushState(PAD_INPUT_10);

    //左矢印キーが離されていればゲームクリアシーンに移行
    if (leftKeyPushState == InputManager::JustRelease)
    {
        nextScene = new GameClearScene();
    }
    //右矢印キーが離されていればゲームオーバーシーンに以降
    else if (rightKeyPushState == InputManager::JustRelease)
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
