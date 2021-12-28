#pragma once
#include "Vector3.h"
#include "Matrix.h"

class MatrixV3 :public Matrix {
public:
	Vector3* v3 = NULL;//需要和图形的点数组进行绑定，不然后期处理麻烦
	int v3number = 0;//图形点的个数

	void setMatrix(Vector3* a, int b);//三维顶点数组初始化
	void MultiplyMatrix();//矩阵相乘
	void Scale(double x, double y, double z);//缩放
	void Rotation_About_X(double alpha);//绕X轴旋转
	void Rotation_About_Y(double beta);//绕Y轴旋转
	void Rotation_About_Z(double gamma);//绕Z轴旋转
	void Rotation(double alpha, double beta, double gamma);//欧拉角
	void Translation(double x, double y,double z);//平移
};