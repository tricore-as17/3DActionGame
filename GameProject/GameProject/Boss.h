#pragma once
#include"CollisionData.h"

class ModelDataManager;
class CollisionManager;


/// <summary>
/// ボスのクラス
/// </summary>
class Boss
{
public:

    /// <summary>
    /// アニメーションの状態
    /// </summary>
    enum AnimationState
    {
        Attack       = 0,    //攻撃
        Dead         = 1,    //死亡
        FireBleth    = 2,    //ブレス攻撃
        GroundAttack = 3,    //地面に攻撃
        Idle         = 4,    //静止
        Intimidation = 5,    //登場時の威嚇
        JumpAttack   = 6,    //ジャンプして攻撃
        LeftShot     = 7,    //左手で撃つショット
        RightShot    = 8,    //右手で撃つショット
        RightTurn    = 9,    //右向き切り替え
        Run          = 10,   //走る
        SitDown      = 11,   //座っている状態
        Standing     = 12,   //立つ動作
        Walk         = 13    //歩き
    };
    //コンストラクタ
    Boss();
    //デストラクタ
    ~Boss();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

private:
    //定数
    static const VECTOR InitialPosition;             //初期座標
    static constexpr float CollisionCapsuleLineLength = 60.0f;   //当たり判定に必要なカプセルの線分の長さ
    static constexpr float CollisionRadius            = 23.0f;   //当たり判定に必要なカプセルの半径の大きさ
    static constexpr float HalfLength                 = 0.5f;    //中央座標を出す際の長さを半分にするための定数
    static constexpr int   NotRegisterTag             = -1;      //レジスタの識別番号が代入されていないことをしめす
    static constexpr float DefaultScale               = 0.15f;    //基本的なスケール

    //メンバ変数
    int modelHandle;                    //モデルハンドル
    int registerTag;                    //レジスタの識別番号
    VECTOR position;                    //座標
    CollisionData collisionData;        //当たり判定に必要な情報
    CollisionManager* collisionManager; //当たり判定管理クラスにアクセスするポインタ


    /// <summary>
    /// ボスの情報から当たり判定に必要な情報を出して代入
    /// </summary>
    void ConvertCollisionData();

    /// <summary>
    /// オブジェクトに当たった際の処理を書いたもの
    /// </summary>
    /// <param name="">当たり判定に必要な情報をまとめたデータ</param>
    void OnHit(CollisionData collisionData);

    /// <summary>
    /// 当たり判定データの更新したものを送る
    /// </summary>
    void SendRegister();

};
