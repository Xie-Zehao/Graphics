#include "MatrixV2.h"
#define _USE_MATH_DEFINES // 这个是PI的定义
#include<math.h>

void MatrixV2::setMatrix(Vector2* a, int b) {//需要传入二维点的个数和数组名字来进行绑定
	this->v2 = a;
	this->v2number = b;
}

void MatrixV2::MultiplyMatrix() {//二维点的变换
	for (int i = 0; i < v2number; i++) {
		v2[i].x = T[0][0] * v2[i].x + T[0][1] * v2[i].y + T[0][2] * v2[i].w;
		v2[i].y = T[1][0] * v2[i].x + T[1][1] * v2[i].y + T[1][2] * v2[i].w;
		v2[i].w = T[2][0] * v2[i].x + T[2][1] * v2[i].y + T[2][2] * v2[i].w;
	}
}

void MatrixV2::Scale(float x, float y)
{
	Identity();
	T[0][0] = x;
	T[1][1] = y;
	MultiplyMatrix();
}

void MatrixV2::Rotation(float beta)
{
	Identity();
	T[0][0] = cos(beta * 180 / M_PI); T[0][1] = -sin(beta * 180 / M_PI);
	T[1][0] = sin(beta * 180 / M_PI); T[1][1] = cos(beta * 180 / M_PI);
	MultiplyMatrix();
}
void MatrixV2::Translation(float x, float y){
	Identity();
	T[0][2] = x;
	T[1][2] = y;
	MultiplyMatrix();
}//平移

