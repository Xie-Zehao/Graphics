#pragma once
#include "Vector3.h"
#include"Vector2.h"
class Triangle {
public:
	Triangle();
	Triangle(Vector3 Point[3]);
	~Triangle();
	Vector3 P[3];
	//������ű任�������
	Vector3 RP[3];
	void setRP(Vector3 *Point);
};
//�ж��������ĵ�������ε�λ��
int inside(Triangle tri, float x, float y);