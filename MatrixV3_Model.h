#pragma once
#include "Vector3.h"
#include "Matrix.h"

class MatrixV3_Model :public Matrix {
public:
	Vector3* v3 = NULL;//创建数组
	int v3number =0 ;//用来记录多少组数据
	void Scale(float x, float y, float z);//缩放
	void Rotation_About_X(float alpha);//绕X轴旋转
	void Rotation_About_Y(float beta);//绕Y轴旋转
	void Rotation_About_Z(float gamma);//绕Z轴旋转
	void Rotation(float alpha, float beta, float gamma);//欧拉角
	void Translation(float x, float y,float z);//平移
};