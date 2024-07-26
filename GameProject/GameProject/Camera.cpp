#include"DxLib.h"
#include"Camera.h"

/// <summary>
/// コンストラクタ
/// </summary>
Camera::Camera()
{
    //奥行0.1～1000までをカメラの描画範囲とする
    SetCameraNearFar(0.1f, 1000.0f);
    //座標の初期化
    position = VGet(0, 40, -50);
    //ToDo
    // 現時点では固定位置を見るように設定しているが
    // プレイヤーを追従するように要修正
    // カメラに位置を反映.
    SetCameraPositionAndTarget_UpVecY(position, VGet(0,0,0));
}

/// <summary>
/// デストラクタ
/// </summary>
Camera::~Camera()
{
    //処理なし
}


/// <summary>
/// 更新処理
/// </summary>
void Camera::Update()
{
    //現時点では処理なし
}
