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
	Vector3 operator= (const Vector3& v1);//重载赋值运算符
	float getmagnitude();
	float getsqrMagnitude();
	void Scale(Vector3& scale);
	Vector3 Scale(Vector3& a, Vector3& b);
	void Normalize();
	void ToString();
	void ToString(string format);
	Vector3 zero();
	Vector3 one();
	//z轴，向前
	Vector3 forward();
	//y轴，向上
	Vector3 up();
	//x轴，向右
	Vector3 right();
	//直角规范化
	Vector3 OrthoNormalize(Vector3 normal, Vector3 tangent);
	Vector3  OrthoNormalize(Vector3 normal, Vector3 tengent, Vector3 binormal);
	//移向
	Vector3 MoveTowards(Vector3 current, Vector3 target, float maxDistanceDelta);
	//转向
	Vector3 RotateWowards(Vector3 current, Vector3 target, float maxRadiansDelta, float maxMagnitudeDelta);
	//平滑阻尼
	Vector3 SmoothDamp(Vector3 current, Vector3 target, Vector3 currentVelocity, float smoothTime, float maxSpeed, float deltaTime);
	//叉乘
	Vector3 Cross(Vector3& lhs, Vector3& rhs);
	//反射
	Vector3 Reflect(Vector3 inDirection, Vector3 inNormal);
	//点乘
	float Dot(Vector3& lhs, Vector3& rhs);
	//投影
	Vector3 Project(Vector3& a, Vector3& b);
	//角度
	float Angle(Vector3& from, Vector3& to);
	//距离
	float Distance(Vector3& a, Vector3& b);
	//限制长度
	Vector3 ClampMagnitude(Vector3 vector, float maxLength);
	//返回最小组件组成的向量
	Vector3 Min(Vector3& lhs, Vector3& rhs);
	//返回最大组件组成的向量
	Vector3 Max(Vector3& lhs, Vector3& rhs);
	friend Vector3 Lerp(Vector3& from, Vector3& to, float t);
	friend float operator*(Vector3& v1, Vector3& v2);//重载点乘
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
//线性插值
Vector3 Lerp(Vector3& from, Vector3& to, float t);
//重载相加
Vector3 operator+(Vector3& v1, Vector3& v2);
//重载相减
Vector3& operator-(Vector3& v1, Vector3& v2);
//重载点乘（向量 * 向量）
float operator*(Vector3& v1, Vector3& v2);
//重载数乘（数 * 向量）
Vector3 operator*(float a, Vector3& b);
//重载数乘（向量 * 数）
Vector3 operator*(Vector3& b, float a);
//重载除法（向量 / 数）
Vector3 operator/(Vector3& b, float a);
//重载等于运算符
bool operator==(Vector3& lhs, Vector3& rhs);
//重载不等于运算符
bool operator!=(Vector3& lhs, Vector3& rhs);