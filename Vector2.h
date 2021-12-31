#pragma once
#include <iostream>
using namespace std;

class Vector2 {
	friend class Matrix;
public:
	Vector2();//无参构造函数
	Vector2(float _x, float _y);//有参构造函数
	Vector2(const Vector2& v1);
	~Vector2();//析构函数
	void ToString();
	float Cross(Vector2 v2);//二维点叉乘
	float getX();
	float getY();
	friend Vector2 operator+(Vector2& v1, Vector2& v2);//重载加法运算符
	friend Vector2 operator-(Vector2& v1, Vector2& v2);//重载减法运算符
	friend Vector2 operator*(Vector2& v1, float m);//重载乘法运算符: 点 乘 数
	friend Vector2 operator*(float m, Vector2& v1);//重载乘法运算符: 数 乘 点
	friend Vector2 operator/(Vector2& v1, float m);//重载除法运算符; 点 除 数
	friend Vector2& operator+=(Vector2& v1, const Vector2& v2);//重载+=
	friend Vector2& operator-=(Vector2& v1, const Vector2& v2);//重载-=
	friend Vector2& operator*=(Vector2& v1, float m);//重载*=
	friend Vector2& operator/=(Vector2& v1, float m);//重载/=
	float x;
	float y;
	float w;//z为其次坐标
};