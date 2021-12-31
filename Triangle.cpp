#include "Triangle.h"

Triangle::Triangle()
{
	P[0] = Vector3(0, 0, 1);
	P[1] = Vector3(0, 1, 0);
	P[2] = Vector3(1, 0, 0);
}

Triangle::Triangle(Vector3 Point[3])
{
	this->P[0] = Point[0];
	this->P[1] = Point[1];
	this->P[2] = Point[2];
}

Triangle::~Triangle()
{
}

int inside(Triangle tri, double x, double y)
{
	Vector2 v2_S[3];
	double result = 1;
	v2_S[0] = Vector2(tri.P[0].x, tri.P[0].y);
	v2_S[1] = Vector2(tri.P[1].x, tri.P[1].y);
	v2_S[2] = Vector2(tri.P[2].x, tri.P[2].y);
	int flag = 0;//在三角形内就是true，不在就是false
	int n=0;
	Vector2 D(x, y);
	for (int i = 0; i < 3; i++) {
		n = i + 1;
		if (n == 3) {
			n = 0;
		}
		result = result * (v2_S[n] - v2_S[i]).Cross(D - v2_S[i]);
	}
	if (result > 0 || result == 0) {
		flag = 1;
	}
	else {
		flag = 0;
	}
	return flag;
}