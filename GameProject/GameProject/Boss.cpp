#include"DxLib.h"
#include"Boss.h"
#include"ModelDataManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
Boss::Boss()
    :modelDataManager(nullptr)
{
    //モデルマネージャーにアクセスるポインタの代入
    modelDataManager = ModelDataManager::GetInstance();

    //モデルハンドルをもってくる
    modelHandle = MV1DuplicateModel(modelDataManager->GetModelHandle(ModelDataManager::Boss));
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
    //現在処理なし
}

void Boss::Draw()
{
    //モデルの描画
    MV1DrawModel(modelHandle);
}

