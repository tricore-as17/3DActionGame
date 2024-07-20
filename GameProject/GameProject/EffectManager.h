#pragma once
#include<map>

using namespace std;

class EffectManager
{
public:
    /// <summary>
    /// エフェクトの種類
    /// </summary>
    enum EffectTag
    {

    };


    /// <summary>
    /// 自身のインスタンスにアクセスするポインタを渡す
    /// </summary>
    /// <returns></returns>
    static EffectManager* GetInstance() { return effectManager; }

    /// <summary>
    /// インスタンスの作成
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// インスタンスの削除
    /// </summary>
    static void DeleteInstance();

    /// <summary>
    /// 指定されたエフェクトを再生する
    /// </summary>
    /// <param name="imageTag">エフェクトの種類</param>
    static const void PlayEffect(EffectTag effectTag);

private:
    //コンストラクタ
    EffectManager();

    //デストラクタ
    ~EffectManager();

    /// <summary>
    /// 必要なエフェクトをロードする
    /// </summary>
    static void LoadEffect();

    /// <summary>
    /// 読み込んだエフェクトの削除
    /// </summary>
    static void DeleteEffect();

    //自身のポインタ
    static EffectManager* effectManager;

    //メンバ変数
    map<EffectTag, int> effectHandle;           //イメージハンドルをまとめているマップ配列
};


