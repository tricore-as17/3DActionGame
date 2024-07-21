#include"ModelDataManager.h"
#include"DxLib.h"


/// <summary>
/// コンストラクタ
/// </summary>
ModelDataManager::ModelDataManager()
{
    //モデルのロード
    modelHandle.insert(make_pair(Player, MV1LoadModel("Model/playerPico.mv1")));
    modelHandle.insert(make_pair(Boss, MV1LoadModel("Model/BOSS.mv1")));
    modelHandle.insert(make_pair(Stage, MV1LoadModel("Model/map2.mv1")));

}

/// <summary>
/// デストラクタ
/// </summary>
ModelDataManager::~ModelDataManager()
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
void ModelDataManager::CreateInstance()
{
    //インスタンスが作られていなければ作成
    if (modelDataManager == nullptr)
    {
        modelDataManager = new ModelDataManager();
    }
}

/// <summary>
/// インスタンスの削除
/// </summary>
void ModelDataManager::DeleteInstance()
{
    if (modelDataManager != nullptr)
    {
        delete modelDataManager;
    }
}

/// <summary>
/// 指定されたタグのイメージハンドルを渡す
/// </summary>
/// <param name="imageTag">イメージタグ</param>
/// <returns>イメージハンドル</returns>
const int ModelDataManager::GetModelHandle(ModelTag modelTag)
{
    return modelHandle.at(modelTag);
}
