#pragma once

class InputManager
{
public:
    //インスタンスを取得するゲッター
    static InputManager* GetInstance() { return inputManager; }

    //インスタンスを作成する
    static void CreateInstance();

    //インスタンスを削除する
    static void DeleteInstance();

    /// <summary>
    /// キーを離した瞬間をとる
    /// </summary>
    /// <param name="compareKey">チェックしたい入力キー</param>
    /// <returns>キーを離したか</returns>
    static bool IsReleaseKey(const int compareKey);
private:
    //コンストラクタ
    InputManager();
    //デストラクタ
    ~InputManager();

    //自身のポインタ
    static InputManager* inputManager;

    static bool releaseKey;        //キーが離されたか
    static bool isPushedKey;         //キーが押されたか
    static bool onPrevKey;         //キーが押され続けているか
};

