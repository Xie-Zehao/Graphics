#pragma once
#include "Vector2.h"
#include "Matrix.h"
class Screen_Matrix:public Matrix {
public:
	Screen_Matrix();//Ĭ�ϵĹ��캯��
	float T[3][3];
	void SetMatrix(float dx,float dy,Vector2 v2);//����ֵ
	Vector2 Multiply(Vector2 v2);//�˷�
};