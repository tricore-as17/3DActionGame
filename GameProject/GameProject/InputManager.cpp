﻿#include"DxLib.h"
#include"InputManager.h"


//nullポインターを入れる
InputManager* InputManager::inputManager = nullptr;



/// <summary>
/// コンストラクタ
/// </summary>
InputManager::InputManager()
{
    //キーの種類とその番号をマップとして保存
    keyTag.insert(make_pair(SPACE, PAD_INPUT_10));
    keyTag.insert(make_pair(LEFT, PAD_INPUT_LEFT));
    keyTag.insert(make_pair(RIGHT,PAD_INPUT_RIGHT));

    //それぞれのキーの初期化
    for (int i = 0; i < keyTag.size(); i++)
    {
        releaseKey.insert(make_pair(keyTag.at((KeyKinds)(i)), false));
        onKey.insert(make_pair(keyTag.at((KeyKinds)(i)), false));
        onPrevKey.insert(make_pair(keyTag.at((KeyKinds)(i)), false));
    }
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


    releaseKey.at((compareKey)) = false;
    // キー離した瞬間を取る.
    if (onKey.at((compareKey)))
    {
        if (!(input & compareKey))
        {
            onKey.at((compareKey)) = false;
            releaseKey.at((compareKey)) = true;
        }
    }
    else if (onPrevKey.at((compareKey)) == false && (input & compareKey))	//キーが最初に押されたタイミング
    {
        releaseKey.at((compareKey)) = false;
        onKey.at((compareKey)) = true;
    }
    if ((input & compareKey))	//押し続けられている時の処理
    {
        onPrevKey.at((compareKey)) = true;
    }
    else
    {
        onPrevKey.at((compareKey)) = false;
    }
    return releaseKey.at((compareKey));
}
