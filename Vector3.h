#pragma once
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class Vector3 {
	friend class Matrix;
public:
	/*
	* 必须写的默认函数
	*/
	Vector3();//空的构造函数
	Vector3(double x, double y, double z);//有参构造
	Vector3(const Vector3& v1);//拷贝构造
	~Vector3();//析构函数
	
	/*
	* 自己给的函数
	*/
	void Normalize();//单位化向量
	//向量点乘
	double Dot(Vector3& lhs, Vector3& rhs);
	//向量叉乘
	Vector3 Cross(Vector3& lhs, Vector3& rhs);
	Vector3 Cross(Vector3& rhs);
	/*
	* 重载运算符
	*/
	Vector3 operator= (const Vector3& v1);//重载赋值运算符
	friend Vector3 Lerp(Vector3& from, Vector3& to, double t);//重载线性插值
	friend double operator*(Vector3& v1, Vector3& v2);//重载向量乘法
	friend Vector3 operator+(Vector3& v1, Vector3& v2);//重载向量加法
	friend Vector3& operator-(Vector3& v1, Vector3& v2);//重载向量减法
	friend Vector3 operator*(double a, Vector3& b);//重载向量数乘
	friend Vector3 operator*(Vector3& b, double a);//重载向量数乘
	friend Vector3 operator/(Vector3& b, double a);//重载向量除法
	friend bool operator==(Vector3& lhs, Vector3& rhs);//重载向量相等
	friend bool operator!=(Vector3& lhs, Vector3& rhs);//重载向量不相等
	double x = 0;
	double y = 0;
	double z = 0;
	double w = 1;
};
//线性插值
Vector3 Lerp(Vector3& from, Vector3& to, double t);
//重载相加
Vector3 operator+(Vector3& v1, Vector3& v2);
//重载相减
Vector3& operator-(Vector3& v1, Vector3& v2);
//重载取反
Vector3 operator-(Vector3& v1);
//重载点乘（向量 * 向量）
double operator*(Vector3& v1, Vector3& v2);
//重载数乘（数 * 向量）
Vector3 operator*(double a, Vector3& b);
//重载数乘（向量 * 数）
Vector3 operator*(Vector3& b, double a);
//重载除法（向量 / 数）
Vector3 operator/(Vector3& b, double a);
//重载等于运算符
bool operator==(Vector3& lhs, Vector3& rhs);
//重载不等于运算符
bool operator!=(Vector3& lhs, Vector3& rhs);