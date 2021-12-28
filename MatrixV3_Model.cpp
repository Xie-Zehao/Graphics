#include "MatrixV3_Model.h"
#define _USE_MATH_DEFINES // 这个是PI的定义
#include<math.h>


void MatrixV3_Model::Scale(double x, double y, double z)
{
	Identity();
	T[0][0] = x;
	T[1][1] = y;
	T[2][2] = z;
	MultiplyMatrix(T, v3, v3number);
}

void MatrixV3_Model::Rotation_About_X(double alpha)
{
	Identity();
	T[1][1] = cos(alpha * 180 / M_PI); T[1][2] = -sin(alpha * 180 / M_PI);
	T[2][1] = sin(alpha * 180 / M_PI); T[2][2] = cos(alpha * 180 / M_PI);
	MultiplyMatrix(T, v3, v3number);
}

void MatrixV3_Model::Rotation_About_Y(double beta)
{
	Identity();
	T[0][0] = cos(beta * 180 / M_PI); T[0][2] = sin(beta * 180 / M_PI);
	T[2][0] = -sin(beta * 180 / M_PI); T[2][2] = cos(beta * 180 / M_PI);
	MultiplyMatrix(T, v3, v3number);
}

void MatrixV3_Model::Rotation_About_Z(double gamma)
{
	Identity();
	T[0][0] = cos(gamma * 180 / M_PI); T[0][1] = -sin(gamma * 180 / M_PI);
	T[1][0] = sin(gamma * 180 / M_PI); T[1][1] = cos(gamma * 180 / M_PI);
	MultiplyMatrix(T, v3, v3number);
}

void MatrixV3_Model::Rotation(double alpha, double beta, double gamma)
{
	Rotation_About_X(alpha);
	Rotation_About_Y(beta);
	Rotation_About_Z(gamma);
}



void MatrixV3_Model::Translation(double x, double y,double z)
{
	Identity();
	T[0][3] = x;
	T[1][3] = y;
	T[2][3] = z;
	MultiplyMatrix(T, v3, v3number);
}


