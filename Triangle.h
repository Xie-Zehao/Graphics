#pragma once
#include "Vector3.h"
#include"Vector2.h"
class Triangle {
public:
	Triangle();
	Triangle(Vector3 P[3]);
	~Triangle();
	Vector3 P[3];
};
//�ж��������ĵ�������ε�λ��
int inside(Triangle tri, double x, double y);