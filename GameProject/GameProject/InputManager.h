#pragma once
#include<map>

using namespace std;

class InputManager
{
public:
    //キーの種類
    enum KeyKinds
    {
        SPACE = 0,
        LEFT  = 1,
        RIGHT = 2
    };

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
    bool IsReleaseKey(const int compareKey);
private:
    //コンストラクタ
    InputManager();
    //デストラクタ
    ~InputManager();

    //自身のポインタ
    static InputManager* inputManager;


    map<KeyKinds, int> keyTag;        //キーの種類からDxライブラリで使う番号に変換用

    map<int,bool>  releaseKey;        //キーが離されたか
    map<int, bool> isPushedKey;       //キーが押されたか
    map<int, bool> onPrevKey;         //キーが押され続けているか
};

