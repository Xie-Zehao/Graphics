#include<stdio.h>
#include"Matrix.h"

using namespace std;
	Matrix::Matrix() {//�޲ι��캯����ȫ����ʼ��Ϊ1
		Identity();
	}
	Matrix::~Matrix() {}//��������
	void Matrix::Identity() { //ֱ�Ӽ򵥴ֱ�����ֵ��λ����
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
	void MultiplyMatrix(float T[4][4], Vector3* v3, int v3number) {//��Ҫ����任�����ԭ���ĵ�����
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
		for (int i = 0; i < 4; i++) {//����L����
			for (int j = 0; j < 4; j++) {//����R����
				Result.T[i][j] = 0;
				for (int n = 0; n < 4; n++) {//���Ƶڼ���Ԫ��
					Result.T[i][j] += (L.T[i][n] * R.T[n][j]);
				}
			}
		}
		return Result;
	}
