#include"DxLib.h"
#include"Player.h"
#include"ModelDataManager.h"
#include"StateBase.h"
#include"PlayerIdle.h"


/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
    :modelDataManager(nullptr)
    , position(VGet(0, 0, 0))
    , angle(0.0f)
    , nowState(NULL)
    , modelDirection(VGet(0, 0, 0))
{
    //インスタンスを持ってくる
    modelDataManager = ModelDataManager::GetInstance();
    //モデルハンドルをもらう
    modelHandle = modelDataManager->GetModelHandle(ModelDataManager::Player);

    //最初にIdle状態のアニメーションをアタッチしておく
    MV1AttachAnim(modelHandle, Idle, -1);

     //最初のステートを待機状態にする
    nowState = new PlayerIdle(modelHandle,-1);



    //座標の設定
    MV1SetPosition(modelHandle, VGet(0, 0, 0));


}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
    modelDataManager = nullptr;
    //メモリの解放
    delete nowState;
}

/// <summary>
/// 更新処理
/// </summary>
void Player::Update()
{
    //ステート毎のアップデートを行う
    nowState->Update(modelDirection);

    // 移動
    position = VAdd(position, nowState->GetVelocity());
    //モデルの向きを反映
    UpdateAngle();

    MV1SetPosition(modelHandle, position);
    
    //更新処理の後次のループでのステートを代入する
    nextState = nowState->GetNextState();
    //次のループのシーンと現在のシーンが違う場合は移行処理を行う
    if (nowState != nextState)
    {
        ChangeState();
    }



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
/// ステートの移行処理
/// </summary>
void Player::ChangeState()
{
    delete nowState;
    nowState = nextState;
    nextState = NULL;
}



/// <summary>
/// プレイヤーの回転制御
/// </summary>
void Player::UpdateAngle()
{
    // プレイヤーの移動方向にモデルの方向を近づける
    float targetAngle;			// 目標角度
    float difference;			// 目標角度と現在の角度との差

    // 目標の方向ベクトルから角度値を算出する
    targetAngle = static_cast<float>(atan2(modelDirection.x, modelDirection.z));

    // 目標の角度と現在の角度との差を割り出す
    // 最初は単純に引き算
    difference = targetAngle - angle;

    // ある方向からある方向の差が１８０度以上になることは無いので
    // 差の値が１８０度以上になっていたら修正する
    if (difference < -DX_PI_F)
    {
        difference += DX_TWO_PI_F;
    }
    else if (difference > DX_PI_F)
    {
        difference -= DX_TWO_PI_F;
    }

    // 角度の差が０に近づける
    if (difference > 0.0f)
    {
        // 差がプラスの場合は引く
        difference -= AngleSpeed;
        if (difference < 0.0f)
        {
            difference = 0.0f;
        }
    }
    else
    {
        // 差がマイナスの場合は足す
        difference += AngleSpeed;
        if (difference > 0.0f)
        {
            difference = 0.0f;
        }
    }

    // モデルの角度を更新
    angle = targetAngle - difference;
    MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + DX_PI_F, 0.0f));
}










