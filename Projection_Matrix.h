#pragma once
#include "Matrix.h"
/*����Ҫ�Լ�дһ��3x4�ľ���
* Ȼ��дһ���˷�
*/
class Projection_Matrix:public Matrix {
public:
	Projection_Matrix(float x);//Ĭ�Ϲ��캯��
	float T[3][4];//������������
	Vector2 Multiply(Vector3 V3);//�˷�����
};