#include<stdio.h>
#include"Matrix.h"

using namespace std;
	Matrix::Matrix() {//无参构造函数，全部初始化为1
		Identity();
	}
	Matrix::~Matrix() {}//析构函数
	void Matrix::Identity() { //直接简单粗暴，赋值单位矩阵
		T[0][0] = 1; T[0][1] = 0; T[0][2] = 0; T[0][3] = 0;
		T[1][0] = 0; T[1][1] = 1; T[1][2] = 0; T[1][3] = 0;
		T[2][0] = 0; T[2][1] = 0; T[2][2] = 1; T[2][3] = 0;
		T[3][0] = 0; T[3][1] = 0; T[3][2] = 0; T[3][3] = 1;
	}
	void Matrix::ToString() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << " " << T[i][j] << " ";
			}
			cout << endl;
		}
	}
	void MultiplyMatrix(float T[4][4], Vector3* v3, int v3number) {//需要传入变换矩阵和原来的点坐标
		for (int i = 0; i < v3number; i++) {
			v3[i].x = T[0][0] * v3[i].x + T[0][1] * v3[i].y + T[0][2] * v3[i].z + T[0][3] * v3[i].w;
			v3[i].y = T[1][0] * v3[i].x + T[1][1] * v3[i].y + T[1][2] * v3[i].z + T[1][3] * v3[i].w;
			v3[i].z = T[2][0] * v3[i].x + T[2][1] * v3[i].y + T[2][2] * v3[i].z + T[2][3] * v3[i].w;
			v3[i].w = T[3][0] * v3[i].x + T[3][1] * v3[i].y + T[3][2] * v3[i].z + T[3][3] * v3[i].w;
		}
	}
	Matrix& operator*( Matrix &L, Matrix &R)
	{
		Matrix Result;
		for (int i = 0; i < 4; i++) {//控制L矩阵
			for (int j = 0; j < 4; j++) {//控制R矩阵
				Result.T[i][j] = 0;
				for (int n = 0; n < 4; n++) {//控制第几个元素
					Result.T[i][j] += (L.T[i][n] * R.T[n][j]);
				}
			}
		}
		return Result;
	}
