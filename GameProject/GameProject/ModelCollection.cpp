#include"DxLib.h"
#include"ModelCollection.h"

//自身の「ポインタをNULLにしておく
ModelCollection* ModelCollection::modelCollection = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
ModelCollection::ModelCollection()
{
    //モデルのロード
    modelHandle.insert(make_pair(Player, MV1LoadModel("Model/playerPico.mv1")));
    modelHandle.insert(make_pair(Boss, MV1LoadModel("Model/BOSS.mv1")));
    modelHandle.insert(make_pair(Stage, MV1LoadModel("Model/map2.mv1")));

}

/// <summary>
/// デストラクタ
/// </summary>
ModelCollection::~ModelCollection()
{
    //モデルのアンロード
    for (int i = 0; i < modelHandle.size(); i++)
    {
        MV1DeleteModel(modelHandle.at((ModelTag)(i)));
    }
}

/// <summary>
/// インスタンスの作成
/// </summary>
void ModelCollection::CreateInstance()
{
    //インスタンスが作られていなければ作成
    if (modelCollection == nullptr)
    {
        modelCollection = new ModelCollection();
    }
}

/// <summary>
/// インスタンスの削除
/// </summary>
void ModelCollection::DeleteInstance()
{
    if (modelCollection != nullptr)
    {
        delete modelCollection;
    }
}

/// <summary>
/// 指定されたタグのイメージハンドルを渡す
/// </summary>
/// <param name="imageTag">イメージタグ</param>
/// <returns>イメージハンドル</returns>
const int ModelCollection::GetModelHandle(ModelTag modelTag)
{
    return modelHandle.at(modelTag);
}
