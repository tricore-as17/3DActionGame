#pragma once
#include"FadeInOut.h"
#include"SoundManager.h"


class SceneBase abstract
{
public:
    //コンストラクタ
    SceneBase();
    //デストラクタ
    virtual ~SceneBase();

    /// <summary>
    /// 次のシーンベースを返す
    /// </summary>
    /// <returns></returns>
    SceneBase* GetNextScene() { return inputScene; }

    /// <summary>
    /// 更新処理
    /// </summary>
    virtual void Update()abstract;

    /// <summary>
    /// 描画
    /// </summary>
    virtual void Draw()abstract;

private:
    SceneBase* inputScene;       //次のループでのシーンを入れる変数
    FadeInOut* fadeInOut;        //フェードアウトとフェードイン用のクラス
    SoundManager* soundManager;  //サウンドを鳴らすためのクラス
};

