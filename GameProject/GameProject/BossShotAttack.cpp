#include"BossShotAttack.h"
#include"BossRunAttack.h"


///<summary>
///コンストラクタ
///</summary>
BossShotAttack::BossShotAttack(int& InitializeModelHandle, const int beforeAnimationIndex)
    :StateBase(InitializeModelHandle, Boss::LeftShot, beforeAnimationIndex)
{
    //アニメーション速度の初期化
    animationSpeed = InitializeAnimationSpeed;

    //インプットマネージャーのインスタンスをもってくる
    inputManager = InputManager::GetInstance();
}

/// <summary>
/// デストラクタ
/// </summary>
BossShotAttack::~BossShotAttack()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void BossShotAttack::Update(VECTOR& modelDirection, VECTOR& position)
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
void BossShotAttack::ChangeState()
{
    //ToDo
    //BossのAIを作るまではボタンでステートが遷移するようにしている
    if (inputManager->GetKeyPushState(InputManager::LeftStick) == InputManager::Push)
    {
        //ボスの突進攻撃ステートに移行
        nextState = new BossRunAttack(modelhandle, animationIndex);
    }
    else
    {
        nextState = this;
    }
}
