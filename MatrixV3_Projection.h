#pragma once
#include"Vector2.h"
#include"Vector3.h"
#include "Matrix.h"
using namespace std;
class MatrixV3_Projection : public Matrix {
public:
	MatrixV3_Projection(double t, double b, double n, double f, double r, double l);
	void MulOrthoProjectionMatrix(double t, double b, double n, double f, double r, double l);//这个矩阵获得的是正交投影矩阵
};