#pragma once
#include"Vector3.h"
#include "Matrix.h"
class Camera_Matrix :public Matrix {
public:
	void ChangWorldToCamera(int x, int y, int z,Vector3 Cam);
	void ChangWorldToCamera(Vector3 Cam, Vector3 Cam_Direction, Vector3 Cam_UP, Vector3 Cam_Right);
};