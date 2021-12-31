#pragma once
#include <iostream>
using namespace std;

class Vector2 {
	friend class Matrix;
public:
	Vector2();//�޲ι��캯��
	Vector2(float _x, float _y);//�вι��캯��
	Vector2(const Vector2& v1);
	~Vector2();//��������
	void ToString();
	float Cross(Vector2 v2);//��ά����
	float getX();
	float getY();
	friend Vector2 operator+(Vector2& v1, Vector2& v2);//���ؼӷ������
	friend Vector2 operator-(Vector2& v1, Vector2& v2);//���ؼ��������
	friend Vector2 operator*(Vector2& v1, float m);//���س˷������: �� �� ��
	friend Vector2 operator*(float m, Vector2& v1);//���س˷������: �� �� ��
	friend Vector2 operator/(Vector2& v1, float m);//���س��������; �� �� ��
	friend Vector2& operator+=(Vector2& v1, const Vector2& v2);//����+=
	friend Vector2& operator-=(Vector2& v1, const Vector2& v2);//����-=
	friend Vector2& operator*=(Vector2& v1, float m);//����*=
	friend Vector2& operator/=(Vector2& v1, float m);//����/=
	float x;
	float y;
	float w;//zΪ�������
};