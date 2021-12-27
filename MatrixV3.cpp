#include "MatrixV3.h"
#define _USE_MATH_DEFINES // 这个是PI的定义
#include<math.h>

void MatrixV3::setMatrix(Vector3* a, int b) {//需要传入三维点的个数和数组名字来进行绑定
	this->v3 = a;
	this->v3number = b;
}

void MatrixV3::MultiplyMatrix() {//三维点的变换
	for (int i = 0; i < v3number; i++) {
		v3[i].x = T[0][0] * v3[i].x + T[0][1] * v3[i].y + T[0][2] * v3[i].z + T[0][3] * v3[i].w;
		v3[i].y = T[1][0] * v3[i].x + T[1][1] * v3[i].y + T[1][2] * v3[i].z + T[1][3] * v3[i].w;
		v3[i].z = T[2][0] * v3[i].x + T[2][1] * v3[i].y + T[2][2] * v3[i].z + T[2][3] * v3[i].w;
		v3[i].w = T[3][0] * v3[i].x + T[3][1] * v3[i].y + T[3][2] * v3[i].z + T[3][3] * v3[i].w;
	}
}

void MatrixV3::Scale(double x, double y, double z)
{
	Identity();
	T[0][0] = x;
	T[1][1] = y;
	T[2][2] = z;
	MultiplyMatrix();
}

void MatrixV3::Rotation_About_X(double alpha)
{
	Identity();
	T[1][1] = cos(alpha * 180 / M_PI); T[1][2] = -sin(alpha * 180 / M_PI);
	T[2][1] = sin(alpha * 180 / M_PI); T[2][2] = cos(alpha * 180 / M_PI);
	MultiplyMatrix();
}

void MatrixV3::Rotation_About_Y(double beta)
{
	Identity();
	T[0][0] = cos(beta * 180 / M_PI); T[0][2] = sin(beta * 180 / M_PI);
	T[2][0] = -sin(beta * 180 / M_PI); T[2][2] = cos(beta * 180 / M_PI);
	MultiplyMatrix();
}

void MatrixV3::Rotation_About_Z(double gamma)
{
	Identity();
	T[0][0] = cos(gamma * 180 / M_PI); T[0][1] = -sin(gamma * 180 / M_PI);
	T[1][0] = sin(gamma * 180 / M_PI); T[1][1] = cos(gamma * 180 / M_PI);
	MultiplyMatrix();
}

void MatrixV3::Rotation(double alpha, double beta, double gamma)
{
	Rotation_About_X(alpha);
	Rotation_About_Y(beta);
	Rotation_About_Z(gamma);
}



void MatrixV3::Translation(double x, double y,double z)
{
	Identity();
	T[0][3] = x;
	T[1][3] = y;
	T[2][3] = z;
	MultiplyMatrix();
}
