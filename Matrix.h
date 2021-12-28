#pragma once
#include"Vector2.h"
#include"Vector3.h"
using namespace std;

class Matrix {
public:
	friend void MultiplyMatrix(double TT[4][4], Vector3* v3, int v3number);
	/*默认函数*/
	Matrix();
	~Matrix();//析构函数
	/*基类矩阵*/
	void Identity();//单位矩阵初始化
	void ToString();//输出字符串
	double T[4][4];//给一个4x4的矩阵，用多少拿多少就行，给够
};

void MultiplyMatrix(double TT[4][4], Vector3* v3, int v3number);//需要传入变换矩阵和原来的点坐标
Matrix& operator*(Matrix L,Matrix R);//全局函数矩阵相乘