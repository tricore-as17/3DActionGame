#include"PlayerMove.h"
#include"InputManager.h"
#include"Player.h"
#include"PlayerIdle.h"


/// <summary>
/// コンストラクタ
/// </summary>
PlayerMove::PlayerMove(int modelHandle,int beforeAnimationIndex)
    :StateBase(modelHandle,Player::Walk,beforeAnimationIndex)
{
    //インプットマネージャーのアドレスを取得
    inputManager = InputManager::GetInstance();

    //アニメーション速度の初期化
    animationSpeed = 1.4f;


}

/// <summary>
/// デストラクタ
/// </summary>
PlayerMove::~PlayerMove()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void PlayerMove::Update(VECTOR& modelDirection)
{
    velocity = VGet(0, 0, 0);
    //キーの入力状態を取得
    keyInput = inputManager->GetPushKeyKinds();

    //正規化した移動方向を決める
    VECTOR direction = DecisionDirection();
    //キーが入力されていればモデルの向きを変える
    if (keyInput != InputManager::None)
    {
        modelDirection = direction;
    }

    // 移動量を出す
    velocity = VScale(direction, MoveSpeed);

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
void PlayerMove::ChangeState()
{
    //ボタンが押されていない場合静止ステートに移行
    if (keyInput == InputManager::None)
    {
        nextState = new PlayerIdle(modelhandle,animationIndex);
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
    else
    {
        nextState = this;
    }
}

/// <summary>
/// 移動方向の選択
/// </summary>
/// <returns>調整された移動方向</returns>
VECTOR PlayerMove::DecisionDirection()
{
    VECTOR direction = VGet(0, 0, 0);

    switch (keyInput)
    {
    case InputManager::Left:
        //左に移動
        direction = VGet(-1, 0, 0);
        break;
    case InputManager::LeftUp:
        //左奥に移動
        direction = VGet(-1, 0, 1);
        break;
    case InputManager::LeftDown:
        //左手前に移動
        direction = VGet(-1, 0, -1);
        break;
    case InputManager::Right:
        //右に移動
        direction = VGet(1, 0, 0);
        break;
    case InputManager::RightUp:
        //右奥に移動
        direction = VGet(1, 0, 1);
        break;
    case InputManager::RightDown:
        //右手前に移動
        direction = VGet(1, 0, -1);
        break;
    case InputManager::Up:
        //奥に移動
        direction = VGet(0, 0, 1);
        break;
    case InputManager::Down:
        //手前に移動
        direction = VGet(0, 0, -1);
        break;

    default:
        break;
    }

    // 正規化
    if (VSquareSize(direction) > 0)      //directionのサイズを2乗にして返す(二乗にすることでdirectionに値が入っていればifに入る
    {
        direction = VNorm(direction);    //各成分のサイズを１にする
    }

    return direction;


}
