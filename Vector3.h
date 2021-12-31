#pragma once
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class Vector3 {
	friend class Matrix;
public:
	/*
	* ����д��Ĭ�Ϻ���
	*/
	Vector3();//�յĹ��캯��
	Vector3(double x, double y, double z);//�вι���
	Vector3(const Vector3& v1);//��������
	~Vector3();//��������
	
	/*
	* �Լ����ĺ���
	*/
	void Normalize();//��λ������
	//�������
	double Dot(Vector3& lhs, Vector3& rhs);
	//�������
	Vector3 Cross(Vector3& lhs, Vector3& rhs);
	Vector3 Cross(Vector3& rhs);
	/*
	* ���������
	*/
	Vector3 operator= (const Vector3& v1);//���ظ�ֵ�����
	friend Vector3 Lerp(Vector3& from, Vector3& to, double t);//�������Բ�ֵ
	friend double operator*(Vector3& v1, Vector3& v2);//���������˷�
	friend Vector3 operator+(Vector3& v1, Vector3& v2);//���������ӷ�
	friend Vector3& operator-(Vector3& v1, Vector3& v2);//������������
	friend Vector3 operator*(double a, Vector3& b);//������������
	friend Vector3 operator*(Vector3& b, double a);//������������
	friend Vector3 operator/(Vector3& b, double a);//������������
	friend bool operator==(Vector3& lhs, Vector3& rhs);//�����������
	friend bool operator!=(Vector3& lhs, Vector3& rhs);//�������������
	double x = 0;
	double y = 0;
	double z = 0;
	double w = 1;
};
//���Բ�ֵ
Vector3 Lerp(Vector3& from, Vector3& to, double t);
//�������
Vector3 operator+(Vector3& v1, Vector3& v2);
//�������
Vector3& operator-(Vector3& v1, Vector3& v2);
//����ȡ��
Vector3 operator-(Vector3& v1);
//���ص�ˣ����� * ������
double operator*(Vector3& v1, Vector3& v2);
//�������ˣ��� * ������
Vector3 operator*(double a, Vector3& b);
//�������ˣ����� * ����
Vector3 operator*(Vector3& b, double a);
//���س��������� / ����
Vector3 operator/(Vector3& b, double a);
//���ص��������
bool operator==(Vector3& lhs, Vector3& rhs);
//���ز����������
bool operator!=(Vector3& lhs, Vector3& rhs);