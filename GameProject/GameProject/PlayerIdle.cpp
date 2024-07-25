#include"InputManager.h"
#include"Player.h"
#include"PlayerIdle.h"
#include"PlayerMove.h"


/// <summary>
/// コンストラクタ
/// </summary>
PlayerIdle::PlayerIdle(int& modelHandle,const int beforeAnimationIndex)
    :StateBase(modelHandle,Player::Idle,beforeAnimationIndex)
{
    //インプットマネージャーのアドレスを取得
    inputManager = InputManager::GetInstance();

    //アニメーション速度の初期化
    animationSpeed = 0.5f;
}

/// <summary>
/// デストラクタ
/// </summary>
PlayerIdle::~PlayerIdle()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void PlayerIdle::Update(VECTOR& modelDirection)
{
    //入力された値をもってくる
    keyInput = inputManager->GetPushKeyKinds();

    //ステートの切り替え処理を呼ぶ
    ChangeState();

    //アニメーションの再生時間のセット
    UpdateAnimation();

    //シーンが切り替わっていればアニメーションをデタッチ
    if (nextState != this && beforeAnimationIndex != -1)
    {
        MV1DetachAnim(modelhandle, beforeAnimationIndex);
    }

}

/// <summary>
/// ステートの切り替え処理をまとめたもの
/// </summary>
void PlayerIdle::ChangeState()
{

    //何かしらの移動キーが押されていた場合移動ステートに切り返る
    if (keyInput <= InputManager::MoveKeyMaxIndex)
    {
        nextState = new PlayerMove(modelhandle,animationIndex);
    }
    //RBのキーが押されていれば攻撃ステートに変更
    else if (keyInput == InputManager::RB)
    {
    }
    //RTのキーが押されていればデフェンスステートに移行する
    else if (keyInput == InputManager::LT)
    {

    }
    //Aのキーが押されていればジャンプステートに移行
    else if (keyInput == InputManager::A)
    {

    }
    //Bキーが押されていれば回避状態のステート
    else if (keyInput == InputManager::B)
    {

    }
    //LBキーで射撃ステートに移行
    else if (keyInput == InputManager::LB)
    {

    }
    //ステート移行が無ければ自身のポインタを渡す
    else
    {
        nextState = this;
    }
    //ToDo
    //他にも死亡時と被弾時があるが当たり判定作成時に作ります
}

