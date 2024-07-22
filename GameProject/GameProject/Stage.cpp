#include"DxLib.h"
#include"Stage.h"
#include"ModelCollection.h"

//定数の初期化
const VECTOR Stage::InitialPosition = VGet(0, 0, 0);

/// <summary>
/// コンストラクタ
/// </summary>
Stage::Stage()
    :modelCollection(nullptr)
{
    modelCollection = ModelCollection::GetInstance();
    modelHandle = modelCollection->GetModelHandle(ModelCollection::Stage);

    //ステージの座標の初期化
    MV1SetPosition(modelHandle, InitialPosition);
}

/// <summary>
/// デストラクタ
/// </summary>
Stage::~Stage()
{
    modelCollection = nullptr;
}

/// <summary>
/// 描画
/// </summary>
void Stage::Draw()
{
    MV1DrawModel(modelHandle);
}
