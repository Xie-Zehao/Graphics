#include "MatrixV3_View.h"

MatrixV3_View::MatrixV3_View(float posX, float posY, float posZ, float targetX, float targetY, float targetZ, float upX, float upY, float upZ)
{
	Identity();
	//1���������������꣬��������ͷ��λ�����꣬Ҳ��ָ����������
	Vector3 Position(posX, posY, posZ);
	//2������������Ľ�β����
	Vector3 Target(targetX, targetY, targetZ);
	//3�������ȡ������Z�ᣬȻ��λ��һ��
	Vector3 Z = Target - Position; Z.Normalize();
	//4����֪һ����������
	Vector3 Tool = Vector3(upX, upY, upZ);
	//5������������Z ���˵õ�X�ᣬȻ��λ��һ��
	Vector3 X = Position.Cross(Tool, Z); X.Normalize();
	//6��Z����X��õ�Y��Ȼ��λ��һ��
	Vector3 Y = Position.Cross(Z, X); Y.Normalize();
	//7�������������-Z��
	Z = -Z;
	//8����֪������꣬��֪Tview����
	float Tview[4][4];
	Tview[0][3] = -posX;
	Tview[1][3] = -posY;
	Tview[2][3] = -posZ;
	//9����֪�������ϵ��R���� = R��ת�ã���֪Rview����
	float Rview[4][4];
	Rview[0][0] = X.x; Rview[0][1] = X.y; Rview[0][2] = X.z;
	Rview[1][0] = Y.x; Rview[1][1] = Y.y; Rview[1][2] = Y.z;
	Rview[2][0] = Z.x; Rview[2][1] = Z.y; Rview[2][2] = Z.z;
	//10����8�͵�9�����г�����һ�£�����ֱ����R*T��
	T[0][0] = X.x;	T[0][1] = X.y;	T[0][2] = X.z;	T[0][3] = -posX * X.x - posY * X.y - posZ * X.z;
	T[1][0] = Y.x;	T[1][1] = Y.y;	T[1][2] = Y.z;	T[1][3] = -posX * Y.x - posY * Y.y - posZ * Y.z;
	T[2][0] = Z.x;	T[2][1] = Z.y;	T[2][2] = Z.z;	T[2][3] = -posX * Z.x - posY * Z.y - posZ * Z.z;
	T[3][0] = 0;	T[3][1] = 0;	T[3][2] = 0;	T[3][3] = 1;
}