#pragma once

//クラスのプロトタイプ宣言
class SceneBase;
class FrameRateController;

/// <summary>
/// ゲーム全体のシーン管理などを行うクラス
/// </summary>
class Game
{
public:
    //コンストラクト
    Game();
    //デストラクタ
    ~Game();

    /// <summary>
    /// ゲームループをまわす処理
    /// </summary>
    void Update();

    /// <summary>
    /// ゲームを継続するかの判断
    /// </summary>
    /// <returns>継続するかのフラグ</returns>
    bool IsContinueGame();

private:
    /// <summary>
    /// 現在のシーンを削除して次のシーンのポインタを入れる
    /// </summary>
    void ChangeScene();

    SceneBase* nowScene;                            //現在のループでのシーンを保存するポインタ
    SceneBase* nextScene;                           //次のループでのシーンを保存するポインタ
    FrameRateController* frameRateController;       //フレームレート計算用クラス
};
