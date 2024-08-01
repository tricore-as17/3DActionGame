#include"BossRunAttack.h"
#include"BossDead.h"

///<summary>
///コンストラクタ
///</summary>
BossRunAttack::BossRunAttack(int& InitializeModelHandle, const int beforeAnimationIndex)
    :StateBase(InitializeModelHandle, Boss::Run, beforeAnimationIndex)
{
    //アニメーション速度の初期化
    animationSpeed = InitializeAnimationSpeed;
    //インプットマネージャーのインスタンスをもってくる
    inputManager = InputManager::GetInstance();
}

/// <summary>
/// デストラクタ
/// </summary>
BossRunAttack::~BossRunAttack()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void BossRunAttack::Update(VECTOR& modelDirection, VECTOR& position)
{
    //ステートの切り替え処理を呼ぶ
    ChangeState();

    //アニメーションの再生時間のセット
    UpdateAnimation();

    //シーンが切り替わっていればアニメーションをデタッチ
    DetachAnimation(this);

}


/// <summary>
/// ステートの切り替え処理をまとめたもの
/// </summary>
void BossRunAttack::ChangeState()
{
    //ToDo
    //BossのAIを作るまではボタンでステートが遷移するようにしている
    if (inputManager->GetKeyPushState(InputManager::LeftStick) == InputManager::JustRelease)
    {
        nextState = new BossDead(modelhandle, this->GetAnimationIndex());
    }
    else
    {
        nextState = this;
    }
}
