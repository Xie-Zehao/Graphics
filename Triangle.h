#pragma once
#include "Vector3.h"
#include"Vector2.h"
class Triangle {
public:
	Triangle();
	Triangle(Vector3 Point[3]);
	~Triangle();
	Vector3 P[3];
	//用来存放变换后的向量
	Vector3 RP[3];
	void setRP(Vector3 *Point);
};
//判断像素中心点和三角形的位置
int inside(Triangle tri, float x, float y);