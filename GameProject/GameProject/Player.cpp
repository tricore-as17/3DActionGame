#include"DxLib.h"
#include"Player.h"
#include"ModelDataManager.h"


/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
    :position(VGet(0,0,0))
    ,direction(VGet(0,0,0))
{
    //インスタンスを持ってくる
    ModelDataManager* modelDataManager = ModelDataManager::GetInstance();
    //モデルハンドルをもらう
    modelHandle = modelDataManager->GetModelHandle(ModelDataManager::Player);

    //座標の設定
    MV1SetPosition(modelHandle, VGet(0, 0, 0));

}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
void Player::Update()
{
    //ToDo
    //ステート管理でプレイヤーの移動を追加したら
    //y座標が0より低くならないように調節する関数をColisionManagerから呼んで使用する
}

/// <summary>
/// 描画
/// </summary>
void Player::Draw()
{
    //プレイヤーの描画
    MV1DrawModel(modelHandle);
}










