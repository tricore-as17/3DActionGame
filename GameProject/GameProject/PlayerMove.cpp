#include"PlayerMove.h"
#include"InputManager.h"
#include"Player.h"
#include"PlayerIdle.h"
#include"PlayerAttack.h"
#include"PlayerDefense.h"
#include"PlayerRolling.h"
#include"PlayerShotMagic.h"

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
    //入力された値をもってくる
    keyInput = GetJoypadInputState(DX_INPUT_PAD1);

    //正規化した移動方向を決める
    VECTOR direction = DecisionDirection();
    //移動キーが入力されていればモデルの向きを変える

    //移動キーのどれかのビットがたっていれば方向をモデルに反映させる
    if (keyInput & InputManager::MoveKeyIndex)
    {
        modelDirection = direction;
    }
    //ステートの切り替え処理を呼ぶ
    ChangeState();



    // 移動量を出す
    velocity = VScale(direction, MoveSpeed);


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

    //キーの名前を判断するタグの用意
    map<InputManager::KeyKinds, int>keyTag = inputManager->GetKeyTag();
    //RBのキーが押されていれば攻撃ステートに変更
    if (keyInput & keyTag.at(InputManager::RB) || keyInput & keyTag.at(InputManager::RT))
    {
        //押されたボタンによって強攻撃のアニメーションにするか
        //通常攻撃のアニメーションにするか変更する
        Player::AnimationState animationState;
        if (keyInput & keyTag.at(InputManager::RB))
        {
            animationState = Player::Slash;
        }
        else
        {
            animationState = Player::Clash;
        }
        nextState = new PlayerAttack(modelhandle, animationIndex, animationState);
    }
    //LTのキーが押されていればデフェンスステートに移行する
    else if (keyInput & keyTag.at(InputManager::LT))
    {
        nextState = new PlayerDefense(modelhandle, animationIndex);
    }
    //Bキーが押されていれば回避状態のステート
    else if (keyInput & keyTag.at(InputManager::B))
    {
        nextState = new PlayerRolling(modelhandle, animationIndex);
    }
    //LBキーで射撃ステートに移行
    else if (keyInput & keyTag.at(InputManager::LB))
    {
        nextState = new PlayerShotMagic(modelhandle, animationIndex);
    }
    //ステート移行が無ければ自身のポインタを渡す
    else if(keyInput & InputManager::MoveKeyIndex)
    {
        nextState = this;
    }
    //上記の状態にならなかったら静止状態に戻す
    else
    {
        nextState = new PlayerIdle(modelhandle, animationIndex);
    }
}

/// <summary>
/// 移動方向の選択
/// </summary>
/// <param name="index">複数押される場合があるのでそれの添え字</param>
/// <returns>調整された移動方向</returns>
VECTOR PlayerMove::DecisionDirection()
{
    VECTOR direction = VGet(0, 0, 0);
    //キーの名前を判断するタグの用意
    map<InputManager::KeyKinds, int>keyTag = inputManager->GetKeyTag();

    //キーに合わせて移動を行う
    if (keyInput & keyTag.at(InputManager::Left))
    {
        direction = VAdd(direction, VGet(-1, 0, 0));
    }
    if (keyInput & keyTag.at(InputManager::Right))
    {
        direction = VAdd(direction, VGet(1, 0, 0));
    }
    if (keyInput & keyTag.at(InputManager::Up))
    {
        direction = VAdd(direction, VGet(0, 0, 1));
    }
    if (keyInput & keyTag.at(InputManager::Down))
    {
        direction = VAdd(direction, VGet(0, 0, -1));
    }
    

    // 正規化
    if (VSquareSize(direction) > 0)      //directionのサイズを2乗にして返す(二乗にすることでdirectionに値が入っていればifに入る
    {
        direction = VNorm(direction);    //各成分のサイズを１にする
    }

    return direction;

}
