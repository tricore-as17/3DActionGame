#include"ModelDataManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
ModelDataManager::ModelDataManager()
{

}

/// <summary>
/// デストラクタ
/// </summary>
ModelDataManager::~ModelDataManager()
{

}

/// <summary>
/// インスタンスの作成
/// </summary>
void ModelDataManager::CreateInstance()
{

}

/// <summary>
/// インスタンスの削除
/// </summary>
void ModelDataManager::DeleteInstance()
{

}

/// <summary>
/// 指定されたタグのイメージハンドルを渡す
/// </summary>
/// <param name="imageTag">イメージタグ</param>
/// <returns>イメージハンドル</returns>
const int ModelDataManager::GetModelHandle(ModelTag modelTag)
{
    //ToDo
    //プレイヤーなどを追加した際にそのモデルハンドルを返すため
    //今はエラーが起きないように0を返しています。
    int modelHandle = 0;
    return modelHandle;
}
