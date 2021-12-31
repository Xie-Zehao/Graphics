#pragma once
#include <iostream>
using namespace std;

class Vector2 {
	friend class Matrix;
public:
	Vector2();//�޲ι��캯��
	Vector2(double _x, double _y);//�вι��캯��
	Vector2(const Vector2& v1);
	~Vector2();//��������
	void ToString();
	double Cross(Vector2 v2);//��ά����
	double getX();
	double getY();
	friend Vector2 operator+(Vector2& v1, Vector2& v2);//���ؼӷ������
	friend Vector2 operator-(Vector2& v1, Vector2& v2);//���ؼ��������
	friend Vector2 operator*(Vector2& v1, double m);//���س˷������: �� �� ��
	friend Vector2 operator*(double m, Vector2& v1);//���س˷������: �� �� ��
	friend Vector2 operator/(Vector2& v1, double m);//���س��������; �� �� ��
	friend Vector2& operator+=(Vector2& v1, const Vector2& v2);//����+=
	friend Vector2& operator-=(Vector2& v1, const Vector2& v2);//����-=
	friend Vector2& operator*=(Vector2& v1, double m);//����*=
	friend Vector2& operator/=(Vector2& v1, double m);//����/=
	double x;
	double y;
	double w;//zΪ�������
};