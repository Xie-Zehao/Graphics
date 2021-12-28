#pragma once 
#include "Vector2.h"
#include "Matrix.h"

class MatrixV2 :public Matrix{
public:
	Vector2* v2 = NULL;//需要和图形的点数组进行绑定，不然后期处理麻烦
	int v2number = 0;//图形点的个数

	void setMatrix(Vector2* a, int b);//二位顶点矩阵初始化
	void MultiplyMatrix();//矩阵相乘
	void Scale(double x, double y);//缩放
	void Rotation(double beta);//旋转
	void Translation(double x, double y);//平移
};