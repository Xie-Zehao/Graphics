#pragma once
#include"Vector2.h"
#include"Vector3.h"
using namespace std;

class Matrix {
public:
	/*Ĭ�Ϻ���*/
	Matrix();
	~Matrix();//��������

	/*�������*/
	void Identity();//��λ�����ʼ��
	void ToString();//����ַ���
	double T[4][4];//��һ��4x4�ľ����ö����ö��پ��У�����

	/*��ʼMVP����Ҫ����View����*/
	Matrix CreateViewMatrix(double posX,double posY,double posZ, double targetX, double targetY, double targetZ, double upX,double upY,double upZ);//����View����
};