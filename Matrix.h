#pragma once
#include"Vector2.h"
#include"Vector3.h"
using namespace std;

class Matrix {
public:
	/*默认函数*/
	Matrix();
	~Matrix();//析构函数

	/*基类矩阵*/
	void Identity();//单位矩阵初始化
	void ToString();//输出字符串
	double T[4][4];//给一个4x4的矩阵，用多少拿多少就行，给够

	/*开始MVP，需要创建View矩阵*/
	Matrix CreateViewMatrix(double posX,double posY,double posZ, double targetX, double targetY, double targetZ, double upX,double upY,double upZ);//创建View矩阵
};