#pragma once
#include"Vector2.h"
#include"Vector3.h"
#include "Matrix.h"
using namespace std;
class MatrixV3_View : public Matrix {
public:
	MatrixV3_View(double posX, double posY, double posZ, double targetX, double targetY, double targetZ, double upX, double upY, double upZ);
};