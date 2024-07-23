#include"DxLib.h"
#include"InputManager.h"


//nullポインターを入れる
InputManager* InputManager::inputManager = nullptr;
//フラグの初期化
bool InputManager::releaseKey = false;
bool InputManager::isPushedKey = false;
bool InputManager::onPrevKey = false;


/// <summary>
/// コンストラクタ
/// </summary>
InputManager::InputManager()
{
    //処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
InputManager::~InputManager()
{
    //処理なし
}

/// <summary>
/// インスタンスを作成する
/// </summary>
void InputManager::CreateInstance()
{
    //既にインスタンスが確保されているかのチェック
    if (inputManager != nullptr)
    {
        return;
    }

    //シングルトンの作成
    inputManager = new InputManager();
}


/// <summary>
/// インスタンスの削除
/// </summary>
void InputManager::DeleteInstance()
{
    if (inputManager)
    {
        delete inputManager;
    }
    inputManager = nullptr;
}

/// <summary>
/// キーを離した瞬間をとる
/// </summary>
/// <param name="compareKey">チェックしたい入力キー</param>
/// <returns>キーを離したか</returns>
bool InputManager::IsReleaseKey(const int compareKey)
{
    //キー入力
    auto input = GetJoypadInputState(DX_INPUT_KEY_PAD1);


    releaseKey = false;
    // キー離した瞬間を取る.
    if (isPushedKey)
    {
        //キーが押されていないかを確認してフラグを切り替える
        if (!(input & PAD_INPUT_10))
        {
            isPushedKey = false;
            releaseKey = true;
        }
    }
    else if (onPrevKey == false && (input & PAD_INPUT_10))	//キーが最初に押されたタイミング
    {
        releaseKey = false;
        isPushedKey = true;
    }
    if ((input & PAD_INPUT_10))	//押し続けられている時の処理
    {
        onPrevKey = true;
    }
    else
    {
        onPrevKey = false;
    }
    return releaseKey;
}
