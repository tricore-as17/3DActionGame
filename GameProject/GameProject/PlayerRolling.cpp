#include"PlayerRolling.h"
#include"PlayerHit.h"
#include"PlayerIdle.h"
#include"Player.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="InitalModelHandle">モデルハンドル</param>
PlayerRolling::PlayerRolling(int initalModelHandle, int beforeAnimationIndex)
    :StateBase(initalModelHandle, Player::Rolling,beforeAnimationIndex)
{
    // 現在のステートを入れる
    nowStateTag = Player::RollingState;

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
/// <param name="position">自身のモデルの向き</param>
/// <param name="position">自身のキャラクターの座標</param>
/// <param name="targetPosition">敵対しているキャラの座標</param>
void PlayerRolling::Update(VECTOR& modelDirection, VECTOR& position,const VECTOR targetPosition,VECTOR cameraPosition)
{
    //ステートの切り替え処理を呼ぶ
    ChangeState();
    //アニメーションの再生時間のセット
    UpdateAnimation();

    //シーンが切り替わっていればアニメーションをデタッチ
    DetachAnimation();
}

/// <summary>
/// ステートの切り替え処理をまとめたもの
/// </summary>
void PlayerRolling::ChangeState()
{
    // ダメージを受けていたらヒットステートに移行
    if (lifeState == Player::Damaged)
    {
        nextState = new PlayerHit(modelhandle, animationIndex, Player::Impact);
    }
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
