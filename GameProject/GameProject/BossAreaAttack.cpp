#include"Boss.h"
#include"BossAreaAttack.h"
#include"BossShotAttack.h"

///<summary>
///コンストラクタ
///</summary>
BossAreaAttack::BossAreaAttack(int& InitializeModelHandle, const int beforeAnimationIndex)
    :StateBase(InitializeModelHandle, Boss::GroundAttack, beforeAnimationIndex)
{
    //アニメーション速度の初期化
    animationSpeed = InitializeAnimationSpeed;

    inputManager = InputManager::GetInstance();
}

/// <summary>
/// デストラクタ
/// </summary>
BossAreaAttack::~BossAreaAttack()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void BossAreaAttack::Update(VECTOR& modelDirection, VECTOR& position)
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
void BossAreaAttack::ChangeState()
{
    //ToDo
    //BossのAIを作るまではボタンでステートが遷移するようにしている
    if (inputManager->GetKeyPushState(InputManager::LeftStick) == InputManager::Push)
    {
        //ボスの移動ステートに移行
        nextState = new BossShotAttack(modelhandle, animationIndex);
    }
    else
    {
        nextState = this;
    }
}
