#pragma once

class Camera
{
public:
    //コンストラクタ
    Camera();
    //デストラクタ
    ~Camera();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

private:
    VECTOR position;    //座標
};
