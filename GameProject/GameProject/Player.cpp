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

    //文字コードの変更
    MV1SetScale(modelHandle, VGet(DefaultScale, DefaultScale, DefaultScale));
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
    //AdjustGroundToWardVelocityも追加する
}

/// <summary>
/// 描画
/// </summary>
void Player::Draw()
{
    //プレイヤーの描画
    MV1DrawModel(modelHandle);
}


/// <summary>
/// 地面に向けたベクトルの調整
/// </summary>
/// <param name="velocity">プレイヤーのベロシティ</param>
/// <returns>調整したベロシティ</returns>
VECTOR Player::AdjustGroundToWardVelocity(VECTOR velocity)
{

    VECTOR adjustVelocity = velocity;
    //地面にめり込まなくなるまで戻す
    while (true)
    {
        //未来のY座標を出す
        float futureYPosition = position.y + adjustVelocity.y;
        //座標が0より下回っていたら修正する
        if (futureYPosition < 0)
        {
            adjustVelocity.y += AdjustVelocityY;
        }
        else
        {
            break;
        }

    }

    //調整した値を返す
    return adjustVelocity;
    
}







