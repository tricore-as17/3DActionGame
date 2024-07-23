#pragma once
#include<map>

using namespace std;

class InputManager
{
public:
    //キーの種類
    enum KeyKinds
    {
        Space      = 0,  //スペース
        Left       = 1,  //右矢印
        Right      = 2,  //左矢印
        Up         = 3,  //上矢印
        Down       = 4,  //下矢印
        LB         = 5,  //左上の手前のボタン
        LT         = 6,  //左上の奥側のボタン
        RB         = 7,  //右上の手前のボタン
        RT         = 8,  //右奥側のボタン
        X          = 9,
        Y          = 10,
        A          = 11,
        B          = 12,
        LeftStick  = 13,  //左スティック押し込み

    };

    //キーの押されている状態
    enum KeyPushState
    {
        NotPush     = 0,  //押されていない
        JustRelease = 1,  //離された瞬間
        Push        = 2,  //押されている
    };

    //インスタンスを取得するゲッター
    static InputManager* GetInstance() { return inputManager; }

    //インスタンスを作成する
    static void CreateInstance();

    //インスタンスを削除する
    static void DeleteInstance();

    /// <summary>
    /// キーの入力状態を取得
    /// </summary>
    /// <param name="compareKey">チェックしたい入力キー</param>
    /// <returns>キーを離したか</returns>
     KeyPushState GetKeyPushState(const int compareKey);
private:
    //コンストラクタ
    InputManager();
    //デストラクタ
    ~InputManager();

    //自身のポインタ
    static InputManager* inputManager;


    map<KeyKinds, int> keyTag;        //キーの種類からDxライブラリで使う番号に変換用

    map<int,KeyPushState>  keyPushState;     //キーが離されたか
};

