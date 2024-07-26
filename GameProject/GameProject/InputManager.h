#pragma once
#include<map>
#include<vector>

using namespace std;

class InputManager
{
public:
    //キーの種類
    enum KeyKinds
    {
        Move       = 0,  //移動キーのどれか
        Left       = 1,  //右
        Right      = 2,  //左
        Up         = 3,  //上
        Down       = 4,  //下
        Space      = 5,  //スペース
        LB         = 6,  //左上の手前のボタン
        LT         = 7,  //左上の奥側のボタン
        RB         = 8,  //右上の手前のボタン
        RT         = 9,  //右奥側のボタン
        X          = 10,
        Y          = 11,
        A          = 12,
        B          = 13,
        LeftStick  = 14,  //左スティック押し込み
        None       = 15,  //使用しないキーもしくは押されていない

    };

    //キーの押されている状態
    enum KeyPushState
    {
        NotPush     = 0,  //押されていない
        JustRelease = 1,  //離された瞬間
        Push        = 2,  //押されている
    };

    //定数
    static constexpr int MoveKeyIndex = 0x0000000f;   //移動キーのどれかがおされているかの指標

    //インスタンスを取得するゲッター
    static InputManager* GetInstance() { return inputManager; }

    /// <summary>
    /// Dxライブラリのキーの認識番号と名前がセットになったマップを返す
    /// </summary>
    /// <returns> Dxライブラリのキーの認識番号と名前がセットになったマップ</returns>
    const map<KeyKinds, int> GetKeyTag()const { return keyTag; }

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


    map<KeyKinds, int> keyTag;                //キーの種類からDxライブラリで使う番号に変換用
    map<int, KeyKinds> reverseKeyTag;         //キータグの要素とキーを入れ替えたもの

    map<int,KeyPushState>  keyPushState;     //キーが離されたか
};

