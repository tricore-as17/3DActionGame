#include"InputManager.h"
#include"Player.h"
#include"PlayerIdle.h"
#include"PlayerMove.h"
#include"PlayerAttack.h"
#include"PlayerDefense.h"
#include"PlayerRolling.h"
#include"PlayerShotMagic.h"


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
    keyInput = GetJoypadInputState(DX_INPUT_PAD1);

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
    //キーの名前を判断するタグの用意
    map<InputManager::KeyKinds, int>keyTag = inputManager->GetKeyTag();

    //何かしらの移動キーが押されていた場合移動ステートに切り返る
    if (keyInput & InputManager::MoveKeyIndex)
    {
        nextState = new PlayerMove(modelhandle,animationIndex);
    }
    //RBのキーかRTキーが押されていれば攻撃ステートに変更
    else if (keyInput & keyTag.at(InputManager::RB) || keyInput & keyTag.at(InputManager::RT))
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
        nextState = new PlayerAttack(modelhandle, animationIndex,animationState);
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
    else
    {
        nextState = this;
    }
    //ToDo
    //他にも死亡時と被弾時があるが当たり判定作成時に作ります
}

