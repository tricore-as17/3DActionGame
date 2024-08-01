#include"PlayerRolling.h"
#include"PlayerIdle.h"
#include"Player.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="InitalModelHandle">モデルハンドル</param>
PlayerRolling::PlayerRolling(int initalModelHandle, int beforeAnimationIndex)
    :StateBase(initalModelHandle, Player::Rolling,beforeAnimationIndex)
{
    //アニメーション速度の初期化
    animationSpeed = 1.0f;
}


/// <summary>
/// デストラクタ
/// </summary>
PlayerRolling::~PlayerRolling()
{

}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void PlayerRolling::Update(VECTOR& modelDirection, VECTOR& position)
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
void PlayerRolling::ChangeState()
{
    //アニメーションの再生が終了したらステートを切り替える
    if (currentPlayAnimationState == FirstRoopEnd)
    {
        nextState = new PlayerIdle(modelhandle, this->GetAnimationIndex());
    }
    else
    {
        nextState = this;
    }
}
