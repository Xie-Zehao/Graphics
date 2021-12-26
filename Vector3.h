#pragma once
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class Vector3 {
	friend class Matrix;
public:
	Vector3();
	Vector3(float x, float y, float z);
	Vector3(const Vector3& v1);
	~Vector3();
	Vector3 operator= (const Vector3& v1);//���ظ�ֵ�����
	float getmagnitude();
	float getsqrMagnitude();
	void Scale(Vector3& scale);
	Vector3 Scale(Vector3& a, Vector3& b);
	void Normalize();
	void ToString();
	void ToString(string format);
	Vector3 zero();
	Vector3 one();
	//z�ᣬ��ǰ
	Vector3 forward();
	//y�ᣬ����
	Vector3 up();
	//x�ᣬ����
	Vector3 right();
	//ֱ�ǹ淶��
	Vector3 OrthoNormalize(Vector3 normal, Vector3 tangent);
	Vector3  OrthoNormalize(Vector3 normal, Vector3 tengent, Vector3 binormal);
	//����
	Vector3 MoveTowards(Vector3 current, Vector3 target, float maxDistanceDelta);
	//ת��
	Vector3 RotateWowards(Vector3 current, Vector3 target, float maxRadiansDelta, float maxMagnitudeDelta);
	//ƽ������
	Vector3 SmoothDamp(Vector3 current, Vector3 target, Vector3 currentVelocity, float smoothTime, float maxSpeed, float deltaTime);
	//���
	Vector3 Cross(Vector3& lhs, Vector3& rhs);
	//����
	Vector3 Reflect(Vector3 inDirection, Vector3 inNormal);
	//���
	float Dot(Vector3& lhs, Vector3& rhs);
	//ͶӰ
	Vector3 Project(Vector3& a, Vector3& b);
	//�Ƕ�
	float Angle(Vector3& from, Vector3& to);
	//����
	float Distance(Vector3& a, Vector3& b);
	//���Ƴ���
	Vector3 ClampMagnitude(Vector3 vector, float maxLength);
	//������С�����ɵ�����
	Vector3 Min(Vector3& lhs, Vector3& rhs);
	//������������ɵ�����
	Vector3 Max(Vector3& lhs, Vector3& rhs);
	friend Vector3 Lerp(Vector3& from, Vector3& to, float t);
	friend float operator*(Vector3& v1, Vector3& v2);//���ص��
	friend Vector3 operator+(Vector3& v1, Vector3& v2);
	friend Vector3& operator-(Vector3& v1, Vector3& v2);
	friend Vector3 operator*(float a, Vector3& b);
	friend Vector3 operator*(Vector3& b, float a);
	friend Vector3 operator/(Vector3& b, float a);
	friend bool operator==(Vector3& lhs, Vector3& rhs);
	friend bool operator!=(Vector3& lhs, Vector3& rhs);
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 1;
	//Vector3 normalized;
};
//���Բ�ֵ
Vector3 Lerp(Vector3& from, Vector3& to, float t);
//�������
Vector3 operator+(Vector3& v1, Vector3& v2);
//�������
Vector3& operator-(Vector3& v1, Vector3& v2);
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