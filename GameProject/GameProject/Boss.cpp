#include"DxLib.h"
#include"Boss.h"
#include"ModelDataManager.h"

//初期座標の入力
const VECTOR Boss::InitialPosition = VGet(0, 0, 6);

/// <summary>
/// コンストラクタ
/// </summary>
Boss::Boss()
    :modelDataManager(nullptr)
    ,position(InitialPosition)
{
    //モデルマネージャーにアクセスるポインタの代入
    modelDataManager = ModelDataManager::GetInstance();

    //モデルハンドルをもってくる
    modelHandle = MV1DuplicateModel(modelDataManager->GetModelHandle(ModelDataManager::Boss));


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

    modelDataManager = nullptr;
}

/// <summary>
/// 更新処理
/// </summary>
void Boss::Update()
{
    //ToDo
    //ステート管理でプレイヤーの移動を追加したら
    //y座標が0より低くならないように調節する関数をUtilityから呼んで使用する
}

void Boss::Draw()
{
    //モデルの描画
    MV1DrawModel(modelHandle);
}

