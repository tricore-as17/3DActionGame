#include"DxLib.h"
#include"StateBase.h"




/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="modelHandle">モデルハンドル</param>
/// <param name="animationState">アニメーションの状態</param>
StateBase::StateBase(int& modelHandle,Player::AnimationState animationState,const int beforeAnimationIndex)
    :velocity(VGet(0,0,0))
    ,animationBlendRate(0.0f)
    ,beforeAnimationIndex(-1)
    ,currentPlayAnimationState(BlendStart)
{
    //もってきたモデルハンドルを代入
    this->modelhandle = modelHandle;
    //アニメーションをアタッチ
    animationIndex = MV1AttachAnim(this->modelhandle, (int)(animationState), -1, FALSE);
    //アニメーションの総再生時間を取得
    animationLimitTime = MV1GetAttachAnimTotalTime(this->modelhandle, animationIndex);
    //アニメーションの再生時間の初期化
    animationNowTime = 0.0f;
    //前回のアニメーションの添え字を代入
    this->beforeAnimationIndex = beforeAnimationIndex;


}

/// <summary>
/// デストラクタ
/// </summary>
StateBase::~StateBase()
{
    //処理なし
}

/// <summary>
/// アニメーションの更新処理
/// </summary>
void StateBase::UpdateAnimation()
{
    //前回のアニメーションがある場合
    if (beforeAnimationIndex != -1 && currentPlayAnimationState == BlendStart)
    {
        //前回とのアニメーションをブレンドして表示
        animationBlendRate += 0.1f;
        //ブレンドが終わったら
        if (animationBlendRate >= 1.0f)
        {
            currentPlayAnimationState = BlendEnd;
            //前のアニメーションをでタッチ
            MV1DetachAnim(modelhandle, beforeAnimationIndex);
            beforeAnimationIndex = -1;
        }
        MV1SetAttachAnimBlendRate(modelhandle, beforeAnimationIndex, 1.0f - animationBlendRate);
        MV1SetAttachAnimBlendRate(modelhandle, animationIndex, animationBlendRate);
    }
    else if(currentPlayAnimationState != Stop)
    {
        //再生時間を進める
        animationNowTime += animationSpeed;
        // 再生時間をセットする
        MV1SetAttachAnimTime(modelhandle, animationIndex, animationNowTime);
        // 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
        if (animationNowTime >= animationLimitTime)
        {
            animationNowTime = 0.0f;
            currentPlayAnimationState = FirstRoopEnd;
        }
    }

}

/// <summary>
/// アニメーションを止める処理
/// </summary>
void StateBase::StopAnimation()
{
    currentPlayAnimationState = Stop;
}

