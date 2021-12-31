#pragma once
#include"Vector2.h"
#include"Vector3.h"
#include "Matrix.h"
using namespace std;
class MatrixV3_View : public Matrix {
public:
	MatrixV3_View(float posX, float posY, float posZ, float targetX, float targetY, float targetZ, float upX, float upY, float upZ);
};