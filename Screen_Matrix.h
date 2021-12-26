#pragma once
#include "Vector2.h"
#include "Matrix.h"
class Screen_Matrix:public Matrix {
public:
	Screen_Matrix();//默认的构造函数
	float T[3][3];
	void SetMatrix(float dx,float dy,Vector2 v2);//给赋值
	Vector2 Multiply(Vector2 v2);//乘法
};