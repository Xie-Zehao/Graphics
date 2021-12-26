#pragma once
#include "Matrix.h"
/*我需要自己写一个3x4的矩阵
* 然后写一个乘法
*/
class Projection_Matrix:public Matrix {
public:
	Projection_Matrix(float x);//默认构造函数
	float T[3][4];//定义三行四列
	Vector2 Multiply(Vector3 V3);//乘法函数
};