#include"DxLib.h"
#include"Player.h"
#include"ModelCollection.h"


/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
    :modelCollection(nullptr)
    ,position(VGet(0,0,0))
    ,direction(VGet(0,0,0))
{
    //インスタンスを持ってくる
    modelCollection = ModelCollection::GetInstance();
    //モデルハンドルをもらう
    modelHandle = modelCollection->GetModelHandle(ModelCollection::Player);

    //座標の設定
    MV1SetPosition(modelHandle, VGet(0, 0, 0));

    //文字コードの変更
    MV1SetScale(modelHandle, VGet(DefaultScale, DefaultScale, DefaultScale));
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
    modelCollection = nullptr;
}

/// <summary>
/// 更新処理
/// </summary>
void Player::Update()
{

}

/// <summary>
/// 描画
/// </summary>
void Player::Draw()
{
    //プレイヤーの描画
    MV1DrawModel(modelHandle);
}







