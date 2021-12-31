#include "MatrixV3_Projection.h"
#define _USE_MATH_DEFINES // 这个是PI的定义
#include<math.h>
MatrixV3_Projection::MatrixV3_Projection(double t, double b, double n, double f, double r, double l)
{
	Identity();
	T[0][0] = -2 * n / (r - l);		T[0][2] = -(r + l) / (r - l);
	T[1][1] = -2 * n / (t - b);		T[1][2] = -(t + b) / (t - b);
	T[2][2] = (n + f) / (n - f);	T[2][3] = -2 * n * f / (n - f);
	T[3][2] = 1;					T[3][3] = 0;
}

MatrixV3_Projection::MatrixV3_Projection(double FOV, double aspect, double zN, double zF)
{
	Identity();
	double halve = FOV / 2 * M_PI / 180;
	double n = zN;
	double f = zF;
	double t = tan(halve) * n;
	double b = -t;
	double r = t * aspect;
	double l = -r;
	T[0][0] = -2 * n / (r - l);		T[0][2] = -(r + l) / (r - l);
	T[1][1] = -2 * n / (t - b);		T[1][2] = -(t + b) / (t - b);
	T[2][2] = (n + f) / (n - f);	T[2][3] = -2 * n * f / (n - f);
	T[3][2] = 1;					T[3][3] = 0;
}

void MatrixV3_Projection::MulOrthoProjectionMatrix(double t, double b, double n, double f, double r, double l)
{
	//n>f
	Matrix OrithoProjection;
	OrithoProjection.T[0][0] = 2 / (r - l); OrithoProjection.T[0][3] = -(r + l) / (r - l);
	OrithoProjection.T[1][1] = 2 / (t - b); OrithoProjection.T[1][3] = -(t + b) / (t - b);
	OrithoProjection.T[2][2] = 2 / (n - f); OrithoProjection.T[2][3] = -(n + f) / (n - f);
}
