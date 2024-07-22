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







