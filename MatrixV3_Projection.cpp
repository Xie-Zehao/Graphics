#include "MatrixV3_Projection.h"
#define _USE_MATH_DEFINES // 这个是PI的定义
#include<math.h>
MatrixV3_Projection::MatrixV3_Projection(float t, float b, float n, float f, float r, float l)
{
	Identity();
	T[0][0] = 2 * n / (r - l);		T[0][2] = -(r + l) / (r - l);
	T[1][1] = 2 * n / (t - b);		T[1][2] = -(t + b) / (t - b);
	T[2][2] = (n + f) / (n - f);	T[2][3] = 2 * n * f / (f - n);
	T[3][2] = 1;					T[3][3] = 0;
}

MatrixV3_Projection::MatrixV3_Projection(float FOV, float aspect, float zN, float zF)
{
	Identity();
	float halve = FOV / 2 * M_PI / 180;
	float n = zN;
	float f = zF;
	float t = tan(halve) * n;
	float b = -t;
	float r = t * aspect;
	float l = -r;
	T[0][0] = -2 * n / (r - l);		T[0][2] = -(r + l) / (r - l);
	T[1][1] = -2 * n / (t - b);		T[1][2] = -(t + b) / (t - b);
	T[2][2] = (n + f) / (n - f);	T[2][3] = -2 * n * f / (n - f);
	T[3][2] = 1;					T[3][3] = 0;
}

void MatrixV3_Projection::MulOrthoProjectionMatrix(float t, float b, float n, float f, float r, float l)
{
	//n>f
	Matrix OrithoProjection;
	OrithoProjection.T[0][0] = 2 / (r - l); OrithoProjection.T[0][3] = -(r + l) / (r - l);
	OrithoProjection.T[1][1] = 2 / (t - b); OrithoProjection.T[1][3] = -(t + b) / (t - b);
	OrithoProjection.T[2][2] = 2 / (n - f); OrithoProjection.T[2][3] = -(n + f) / (n - f);
}
