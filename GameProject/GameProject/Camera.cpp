﻿#include"DxLib.h"
#include"Camera.h"

/// <summary>
/// コンストラクタ
/// </summary>
Camera::Camera()
    :angleHorizontal(0)
    ,angleVertical(0)
    ,position(VGet(0,0,0))
    ,targetPosition(VGet(0,0,0))
{
    //カメラの初期水平角度は180度
    angleHorizontal = DX_PI_F;

    //垂直角度は0度
    angleVertical = 0.0f;

    //奥行0.1～1000までをカメラの描画範囲とする
    SetCameraNearFar(0.1f, 1000.0f);
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
void Camera::Update(VECTOR playerPosition)
{

    // カメラの注視点はプレイヤー座標から規定値分高い座標
    targetPosition = VAdd(playerPosition, VGet(0.0f, CameraTargetPlayerHeight, 0.0f));

    // カメラの座標を補正する
    FixCameraPosition();

    // Ｘ軸にカメラとプレイヤーとの距離分だけ伸びたベクトルを
    // 垂直方向回転( Ｚ軸回転 )させたあと水平方向回転( Ｙ軸回転 )して更に
    // 注視点の座標を足したものがカメラの座標
    SetCameraPositionAndTarget_UpVecY(position, targetPosition);
}


/// <summary>
/// カメラの座標補正する
/// </summary>
void Camera::FixCameraPosition()
{
    // 水平方向の回転はＹ軸回転
    auto rotationY = MGetRotY(angleHorizontal);

    // 垂直方向の回転はＺ軸回転 )
    auto rotationX = MGetRotZ(angleVertical);

    position = VAdd(VTransform(VTransform(VGet(0.0f, 0.0f, ToPlayerLength), rotationX), rotationY), targetPosition);


}
