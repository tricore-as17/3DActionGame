#pragma once
#include<map>

using namespace std;

class ImageDataManager
{
public:

    /// <summary>
    /// ロードした画像のタグ
    /// </summary>
    enum ImageTag
    {

    };

    /// <summary>
    /// 自身のインスタンスにアクセスするポインタを渡す
    /// </summary>
    /// <returns></returns>
    static ImageDataManager* GetInstance() { return imageDataManager; }

    /// <summary>
    /// インスタンスの作成
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// インスタンスの削除
    /// </summary>
    static void DeleteInstance();

    /// <summary>
    /// 指定されたタグのイメージハンドルを渡す
    /// </summary>
    /// <param name="imageTag">イメージタグ</param>
    /// <returns>イメージハンドル</returns>
    static const int GetImageHandle(ImageTag imageTag);


private:

    //コンストラクタ
    ImageDataManager();
    //デストラクタ
    ~ImageDataManager();

    /// <summary>
    /// 必要な画像をロードする
    /// </summary>
    static void LoadImage();

    /// <summary>
    /// 読み込んだ画像の削除
    /// </summary>
    static void DeleteImage();

    //自身のポインタ
    static ImageDataManager* imageDataManager;

    //メンバ変数
    map<ImageTag, int> imageHandle;           //イメージハンドルをまとめているマップ配列

};


