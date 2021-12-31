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
	t,b,n,f,r,l�� ��׶�����
	һ����ԣ�
	l=-1,r=1,b=-1,t=1,n=0.1,f=100
	45, 1, 0.1, 50
	*/
	MatrixV3_Projection(double t, double b, double n, double f, double r, double l);

	MatrixV3_Projection(double FOV,double aspect,double n,double f);


	void MulOrthoProjectionMatrix(double t, double b, double n, double f, double r, double l);//��������õ�������ͶӰ����
};