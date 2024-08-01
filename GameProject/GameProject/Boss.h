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
    static const VECTOR InitialPosition;                         //初期座標
    static const VECTOR ModelOffsetPosition;                     //モデルの位置を調整するための値
    static constexpr float CollisionCapsuleLineLength = 60.0f;   //当たり判定に必要なカプセルの線分の長さ
    static constexpr float CollisionRadius            = 23.0f;   //当たり判定に必要なカプセルの半径の大きさ
    static constexpr float HalfLength                 = 0.5f;    //中央座標を出す際の長さを半分にするための定数
    static constexpr int   NotRegisterTag             = -1;      //レジスタの識別番号が代入されていないことをしめす

    //メンバ変数
    int modelHandle;                    //モデルハンドル
    VECTOR position;                    //座標
    CollisionData collisionData;        //当たり判定に必要な情報
    CollisionManager* collisionManager; //当たり判定管理クラスにアクセスするポインタ


    /// <summary>
    /// ボスの情報から当たり判定に必要な情報を出して代入
    /// </summary>
    void UpdateCollisionData();

    /// <summary>
    /// オブジェクトに当たった際の処理を書いたもの
    /// </summary>
    /// <param name="">当たり判定に必要な情報をまとめたデータ</param>
    void OnHit(const CollisionData collisionData);


};
