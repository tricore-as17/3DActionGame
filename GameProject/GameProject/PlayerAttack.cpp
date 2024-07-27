#include"PlayerAttack.h"
#include"StateBase.h"
#include"Player.h"
#include"PlayerIdle.h"


/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="InitalModelHandle">モデルハンドル</param>
/// <param name="beforeAnimationIndex">前のステートでのアニメーション情報</param>
PlayerAttack::PlayerAttack(int InitalModelHandle, int beforeAnimationIndex, Player::AnimationState animationState)
    :StateBase(InitalModelHandle,animationState,beforeAnimationIndex)
{
    //アニメーション速度の初期化
    animationSpeed = 1.0f;
}

/// <summary>
/// デストラクタ
/// </summary>
PlayerAttack::~PlayerAttack()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="position">プレイヤーモデルの向き</param>
void PlayerAttack::Update(VECTOR& modelDirection, VECTOR& position)
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
void PlayerAttack::ChangeState()
{
    //アニメーションの再生が終了したらステートを切り替える
    if (currentPlayAnimationState == FirstRoopEnd)
    {
        nextState = new PlayerIdle(modelhandle, animationIndex);
    }
    else
    {
        nextState = this;
    }
}
