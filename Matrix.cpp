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

	Matrix& Matrix::CreateViewMatrix(double posX, double posY, double posZ, double targetX, double targetY, double targetZ, double upX, double upY, double upZ)
	{
		//1，根据两个点坐标，创建摄像头的位置坐标，也是指向的起点坐标
		Vector3 Position(posX, posY, posZ);
		//2，创建摄像机的结尾坐标
		Vector3 Target(targetX, targetY, targetZ);
		//3，做差获取到方向Z轴，然后单位化一下
		Vector3 Z = Target - Position; Z.Normalize();
		//4，已知一个工具向量
		Vector3 Tool = Vector3(upX, upY, upZ);
		//5，工具向量和Z 轴叉乘得到X轴，然后单位化一下
		Vector3 X = Position.Cross(Tool, Z); X.Normalize();
		//6，Z轴叉乘X轴得到Y，然后单位化一下
		Vector3 Y = Position.Cross(Z, X); Y.Normalize();
		//7，摄像机看的是-Z轴
		Z = -Z;
		//8，已知相机坐标，可知Tview矩阵
		double Tview[4][4];
		Tview[0][3] = -posX;
		Tview[1][3] = -posY;
		Tview[2][3] = -posZ;
		//9，已知相机坐标系，R的逆 = R的转置，可知Rview矩阵
		double Rview[4][4];
		Rview[0][0] = X.x; Rview[0][1] = X.y; Rview[0][2] = X.z;
		Rview[1][0] = Y.x; Rview[1][1] = Y.y; Rview[1][2] = Y.z;
		Rview[2][0] = Z.x; Rview[2][1] = Z.y; Rview[2][2] = Z.z;
		//10，第8和第9就是列出来看一下，这里直接算R*T了
		Matrix View;
		View.T[0][0] = X.x; View.T[0][1] = X.y; View.T[0][2] = X.z; View.T[0][3] = -posX * X.x - posY * X.y - posZ * X.z;
		View.T[1][0] = Y.x; View.T[1][1] = Y.y; View.T[1][2] = Y.z; View.T[1][3] = -posX * Y.x - posY * Y.y - posZ * Y.z;
		View.T[2][0] = Z.x; View.T[2][1] = Z.y; View.T[2][2] = Z.z; View.T[2][3] = -posX * Z.x - posY * Z.y - posZ * Z.z;
		View.T[3][0] = 0;	View.T[3][1] = 0;	View.T[3][2] = 0;	View.T[3][3] = 1;
		return View;
	}

	Matrix& Matrix::CreateOrthoProjectionMatrix(double t, double b, double n, double f, double r, double l)
	{
		//n>f
		Matrix OrithoProjection;
		OrithoProjection.T[0][0] = 2 / (r - l); OrithoProjection.T[0][3] = -(r + l) / (r - l);
		OrithoProjection.T[1][1] = 2 / (t - b); OrithoProjection.T[1][3] = -(t + b) / (t - b);
		OrithoProjection.T[2][2] = 2 / (n - f); OrithoProjection.T[2][3] = -(n + f) / (n - f);
		return OrithoProjection;
	}

	Matrix& Matrix::CreatePerspOrthoProjectionMatrix(double t, double b, double n, double f, double r, double l)
	{
		Matrix Projection;
		Projection.T[0][0] = -2 * n / (r - l);	Projection.T[0][2] = -(r + l) / (r - l);
		Projection.T[1][1] = -2 * n / (t - b);	Projection.T[1][2] = -(t + b) / (t - b);
		Projection.T[2][2] = (n + f) / (n - f);	Projection.T[2][3] = -2 * n * f / (n - f);
		Projection.T[3][2] = 1;					Projection.T[3][3] = 0;
		return Projection;
	}
	

