#pragma once
#include"Vector2.h"
#include"Vector3.h"
using namespace std;

class Matrix {
public:
	friend Vector3* MultiplyMatrix(float TT[4][4], Vector3* v3, int v3number);
	/*Ĭ�Ϻ���*/
	Matrix();
	~Matrix();//��������
	/*�������*/
	void Identity();//��λ�����ʼ��
	void ToString();//����ַ���
	float T[4][4];//��һ��4x4�ľ����ö����ö��پ��У�����
};

Vector3* MultiplyMatrix(float TT[4][4], Vector3* v3, int v3number);//��Ҫ����任�����ԭ���ĵ�����
Matrix& operator*(Matrix &L,Matrix &R);//ȫ�ֺ����������