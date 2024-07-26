#pragma once
#include"StateBase.h"
#include"InputManager.h"

/// <summary>
/// プレイヤーのガードに関するステート
/// </summary>
class PlayerDefense:public StateBase
{
public:
    //コンストラクタ
    PlayerDefense(int modelHandle, int beforeAnimationIndex);
    //デストラクタ
    ~PlayerDefense();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="position">プレイヤーモデルの向き</param>
    void Update(VECTOR& modelDirection, VECTOR& position)override;

    /// <summary>
    /// ステートの切り替え処理をまとめたもの
    /// </summary>
    void ChangeState()override;
private:

    //メンバ変数
    InputManager* inputManager;              //インプットマネージャーにアクセスするためのポインタ
    int keyInput;                            //キーの入力状態
};
