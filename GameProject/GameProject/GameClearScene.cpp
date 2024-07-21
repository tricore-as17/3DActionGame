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
    //スペースキーが押されたかのチェック
    bool isKeyRelease = inputManager->IsReleaseKey(PAD_INPUT_LEFT);

    //左矢印キーが押されていればゲームクリアシーンに以降
    if (isKeyRelease)
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
void GameClearScene::Draw()
{
#ifdef _DEBUG
    DrawString(500, 500, "クリアシーン", GetColor(255, 255, 255));
#endif

}


