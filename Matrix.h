#pragma once
#include"Vector2.h"
#include"Vector3.h"
using namespace std;

class Matrix {
public:
	friend void MultiplyMatrix(double TT[4][4], Vector3* v3, int v3number);
	/*Ĭ�Ϻ���*/
	Matrix();
	~Matrix();//��������
	/*�������*/
	void Identity();//��λ�����ʼ��
	void ToString();//����ַ���
	double T[4][4];//��һ��4x4�ľ����ö����ö��پ��У�����
};

void MultiplyMatrix(double TT[4][4], Vector3* v3, int v3number);//��Ҫ����任�����ԭ���ĵ�����
Matrix& operator*(Matrix L,Matrix R);//ȫ�ֺ����������