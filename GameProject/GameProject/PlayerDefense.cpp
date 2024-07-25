#include"PlayerDefense.h"
#include"PlayerIdle.h"


/// <summary>
/// コンストラクタ
/// </summary>
PlayerDefense::PlayerDefense(int modelHandle, int beforeAnimationIndex)
    :StateBase(modelHandle, Player::StartBlocking, beforeAnimationIndex)
{
    //インプットマネージャーのアドレスを取得
    inputManager = InputManager::GetInstance();

    //アニメーション速度の初期化
    animationSpeed = 1.0f;

}


/// <summary>
/// デストラクタ
/// </summary>
PlayerDefense::~PlayerDefense()
{
    //処理なし
}


/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void PlayerDefense::Update(VECTOR& modelDirection)
{
    //入力された値をもってくる
    keyInput = GetJoypadInputState(DX_INPUT_PAD1);

    //ステートの切り替え処理を呼ぶ
    ChangeState();

    //アニメーションの再生時間のセット
    UpdateAnimation();

    //一回のループが終わればアニメーションの更新を止める
    if (currentPlayAnimationState == FirstRoopEnd)
    {
        StopAnimation();
    }

    //シーンが切り替わっていればアニメーションをデタッチ
    if (nextState != this && beforeAnimationIndex != -1)
    {
        MV1DetachAnim(modelhandle, beforeAnimationIndex);
    }
}

void PlayerDefense::ChangeState()
{
    //キーの名前を判断するタグの用意
    map<InputManager::KeyKinds, int>keyTag = inputManager->GetKeyTag();

    //LTのキーが押されていればデフェンスステートに移行する
    if (keyInput & keyTag.at(InputManager::LT))
    {
        nextState = this;
    }
    else
    {
        nextState = new PlayerIdle(modelhandle, animationIndex);
    }
}
