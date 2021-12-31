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
	Vector3(float x, float y, float z);//�вι���
	Vector3(const Vector3& v1);//��������
	~Vector3();//��������
	
	/*
	* �Լ����ĺ���
	*/
	void Normalize();//��λ������
	//�������
	float Dot(Vector3& lhs, Vector3& rhs);
	//�������
	Vector3 Cross(Vector3& lhs, Vector3& rhs);
	Vector3 Cross(Vector3& rhs);
	/*
	* ���������
	*/
	Vector3 operator= (const Vector3& v1);//���ظ�ֵ�����
	friend Vector3 Lerp(Vector3& from, Vector3& to, float t);//�������Բ�ֵ
	friend float operator*(Vector3& v1, Vector3& v2);//���������˷�
	friend Vector3 operator+(Vector3& v1, Vector3& v2);//���������ӷ�
	friend Vector3& operator-(Vector3& v1, Vector3& v2);//������������
	friend Vector3 operator*(float a, Vector3& b);//������������
	friend Vector3 operator*(Vector3& b, float a);//������������
	friend Vector3 operator/(Vector3& b, float a);//������������
	friend bool operator==(Vector3& lhs, Vector3& rhs);//�����������
	friend bool operator!=(Vector3& lhs, Vector3& rhs);//�������������
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 1;
};
//���Բ�ֵ
Vector3 Lerp(Vector3& from, Vector3& to, float t);
//�������
Vector3 operator+(Vector3& v1, Vector3& v2);
//�������
Vector3& operator-(Vector3& v1, Vector3& v2);
//����ȡ��
Vector3 operator-(Vector3& v1);
//���ص�ˣ����� * ������
float operator*(Vector3& v1, Vector3& v2);
//�������ˣ��� * ������
Vector3 operator*(float a, Vector3& b);
//�������ˣ����� * ����
Vector3 operator*(Vector3& b, float a);
//���س��������� / ����
Vector3 operator/(Vector3& b, float a);
//���ص��������
bool operator==(Vector3& lhs, Vector3& rhs);
//���ز����������
bool operator!=(Vector3& lhs, Vector3& rhs);