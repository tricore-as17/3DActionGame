#include"DxLib.h"
#include"Boss.h"
#include"ModelDataManager.h"
#include"CollisionManager.h"
#include"CollisionData.h"

//初期座標の入力
const VECTOR Boss::InitialPosition = VGet(0, 0, 6);

const VECTOR Boss::ModelOffsetPosition = VGet(-5, 0, -15);

/// <summary>
/// コンストラクタ
/// </summary>
Boss::Boss()
    :position(InitialPosition)
{
    //モデルマネージャーにアクセスるポインタの代入
    ModelDataManager* modelDataManager = ModelDataManager::GetInstance();

    //モデルハンドルをもってくる
    modelHandle = MV1DuplicateModel(modelDataManager->GetModelHandle(ModelDataManager::Boss));

    //コリジョンマネージャーのインスタンスのアドレスを取得
    collisionManager = collisionManager->GetInstance();

    //当たり判定用の変数の初期化
    UpdateCollisionData();
    //識別番号はCollisionManagerが代入するので入っていないことを
    collisionData.collidableObjectTag = CollisionManager::NotRegisterTag;

    //当たり判定データのポインタを渡す
    collisionManager->RegisterCollisionData(&collisionData);

    //座標の設定
    MV1SetPosition(modelHandle, InitialPosition);
}

/// <summary>
/// デストラクタ
/// </summary>
Boss::~Boss()
{
    //モデルの削除
    MV1DeleteModel(modelHandle);

}

/// <summary>
/// 更新処理
/// </summary>
void Boss::Update()
{
    //当たり判定に必要なデータの更新
    UpdateCollisionData();

    //モデルを描画する座標の調整
    MV1SetPosition(modelHandle, VAdd(position, ModelOffsetPosition));
}

void Boss::Draw()
{
    //モデルの描画
    MV1DrawModel(modelHandle);

    //当たり判定が正しいかの確認用の描画
    DrawCapsule3D(collisionData.bottomPosition, collisionData.upPosition, collisionData.radius, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);

}


/// <summary>
/// プレイヤーの情報から当たり判定に必要な情報を出して代入
/// </summary>
void Boss::UpdateCollisionData()
{
    //中央座標の代入
    collisionData.centerPosition = VAdd(position, VGet(0.0f, CollisionCapsuleLineLength * HalfLength, 0.0f));
    //カプセルの下側の座標
    collisionData.bottomPosition = position;
    //カプセルの上側の座標
    collisionData.upPosition = VAdd(position, VGet(0.0f, CollisionCapsuleLineLength, 0.0f));
    //カプセルの球部分の半径
    collisionData.radius = CollisionRadius;
    //オブジェクトの種類
    collisionData.hitObjectTag = CollisionManager::Boss;
    //当たった際の関数
    collisionData.onHit = std::bind(&Boss::OnHit, this, std::placeholders::_1);
}

/// <summary>
/// オブジェクトに当たった際の処理を書いたもの
/// </summary>
/// <param name="">当たり判定に必要な情報をまとめたデータ</param>
void Boss::OnHit(const CollisionData collisionData)
{
    switch (collisionData.hitObjectTag)
    {

    default:
        break;
    }
}



