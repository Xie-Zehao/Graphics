#pragma once
#include "Vector3.h"
#include "Matrix.h"

class MatrixV3_Model :public Matrix {
public:
	Vector3* v3 = NULL;//创建数组
	int v3number =0 ;//用来记录多少组数据
	void Scale(double x, double y, double z);//缩放
	void Rotation_About_X(double alpha);//绕X轴旋转
	void Rotation_About_Y(double beta);//绕Y轴旋转
	void Rotation_About_Z(double gamma);//绕Z轴旋转
	void Rotation(double alpha, double beta, double gamma);//欧拉角
	void Translation(double x, double y,double z);//平移
};