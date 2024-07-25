#pragma once
#include<map>

using namespace std;

class InputManager
{
public:
    //キーの種類
    enum KeyKinds
    {
        Left       = 0,  //右
        LeftUp     = 1,  //左上
        LeftDown   = 2,  //左下
        Right      = 3,  //左
        RightUp    = 4,  //右上
        RightDown  = 5,  //右下
        Up         = 6,  //上
        Down       = 7,  //下
        Space      = 8,  //スペース
        LB         = 9,  //左上の手前のボタン
        LT         = 10,  //左上の奥側のボタン
        RB         = 11,  //右上の手前のボタン
        RT         = 12,  //右奥側のボタン
        X          = 13,
        Y          = 14,
        A          = 15,
        B          = 16,
        LeftStick  = 17,  //左スティック押し込み
        Other      = 18,  //使用しないキーもしくは押されていない

    };

    //キーの押されている状態
    enum KeyPushState
    {
        NotPush     = 0,  //押されていない
        JustRelease = 1,  //離された瞬間
        Push        = 2,  //押されている
    };

    //定数
    static constexpr int MoveKeyMaxIndex = 7;   //移動キーのどれかがおされているかの指標

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

     /// <summary>
     /// 押されているキーを取得
     /// </summary>
     /// <returns>キーの種類</returns>
     KeyKinds GetPushKeyKinds();
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

