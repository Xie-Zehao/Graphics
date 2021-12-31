#pragma once
#include"Vector2.h"
#include"Vector3.h"
#include "Matrix.h"
using namespace std;
class MatrixV3_ViewPort :public Matrix {
public:
	MatrixV3_ViewPort(float width, float height);
};