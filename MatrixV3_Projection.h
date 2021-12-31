#pragma once
#include"Vector2.h"
#include"Vector3.h"
#include "Matrix.h"
using namespace std;
class MatrixV3_Projection : public Matrix {
public:
	/*
	tan(fov / 2) = t/|n|;
	aspect = r/t;
	t,b,n,f,r,l是 视锥体参数
	一般而言：
	l=-1,r=1,b=-1,t=1,n=0.1,f=100
	45, 1, 0.1, 50
	*/
	MatrixV3_Projection(double t, double b, double n, double f, double r, double l);

	MatrixV3_Projection(double FOV,double aspect,double n,double f);


	void MulOrthoProjectionMatrix(double t, double b, double n, double f, double r, double l);//这个矩阵获得的是正交投影矩阵
};