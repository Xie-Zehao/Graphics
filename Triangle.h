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
//判断像素中心点和三角形的位置
int inside(Triangle tri, double x, double y);