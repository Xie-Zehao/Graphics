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

	Matrix Matrix::CreateViewMatrix(double posX, double posY, double posZ, double targetX, double targetY, double targetZ, double upX, double upY, double upZ)
	{
		//1���������������꣬��������ͷ��λ�����꣬Ҳ��ָ����������
		Vector3 Position(posX, posY, posZ);
		//2������������Ľ�β����
		Vector3 Target(targetX, targetY, targetZ);
		//3�������ȡ������Z��
		Vector3 Z = Target - Position;
		//4����֪һ����������
		Vector3 Tool = Vector3(upX, upY, upZ);
		//5������������Z ���˵õ�X��
		Vector3 X = Position.Cross(Tool, Z);
		//6��Z����X��õ�Y 
		Vector3 Y = Position.Cross(Z, X);
		//7�������������-Z��
		Z = -Z;
		//8����֪������꣬��֪Tview����
		double Tview[4][4];
		Tview[0][3] = -posX;
		Tview[1][3] = -posY;
		Tview[2][3] = -posZ;
		//9����֪�������ϵ��R���� = R��ת�ã���֪Rview����
		double Rview[4][4];
		Rview[0][0] = X.x; Rview[0][1] = X.y; Rview[0][2] = X.z;
		Rview[1][0] = Y.x; Rview[1][1] = Y.y; Rview[1][2] = Y.z;
		Rview[2][0] = Z.x; Rview[2][1] = Z.y; Rview[2][2] = Z.z;
		//10����8�͵�9�����г�����һ�£�����ֱ����R*T��
		Matrix View;
		View.T[0][0] = X.x; View.T[0][1] = X.y; View.T[0][2] = X.z; View.T[0][3] = -posX * X.x - posY * X.y - posZ * X.z;
		View.T[1][0] = Y.x; View.T[1][1] = Y.y; View.T[1][2] = Y.z; View.T[1][3] = -posX * Y.x - posY * Y.y - posZ * Y.z;
		View.T[2][0] = Z.x; View.T[2][1] = Z.y; View.T[2][2] = Z.z; View.T[2][3] = -posX * Z.x - posY * Z.y - posZ * Z.z;
		View.T[3][0] = 0;	View.T[3][1] = 0;	View.T[3][2] = 0;	View.T[3][3] = 1;
		return View;
	}
	

