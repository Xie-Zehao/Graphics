 #include"Vector2.h"

Vector2::Vector2() :x(0), y(0), w(1) {}//无参构造函数
Vector2::Vector2(float _x, float _y) : x(_x), y(_y), w(1) {}//有参构造函数
Vector2::Vector2(const Vector2& v1) {
	x = v1.x;
	y = v1.y;
	w = 1;
}//拷贝构造函数
Vector2::~Vector2() {};//析构函数

float Vector2::getX(){
	return x;
}
float Vector2::getY(){
	return y;
}
void Vector2::ToString() {
	cout << "( " << x << ", " << y << ", " << w << ") " << endl;
}
float Vector2::Cross(Vector2 v2)
{
	return x * v2.y - y * v2.x;
}
Vector2 operator+(Vector2& v1, Vector2& v2) {
	Vector2 temp;
	temp.x = v1.x + v2.x;
	temp.y = v1.y + v2.y;
	return temp;
}
Vector2 operator-(Vector2& v1, Vector2& v2) {
	Vector2 temp;
	temp.x = v1.x - v2.x;
	temp.y = v1.y - v2.y;
	return temp;
}
Vector2 operator*(Vector2& v1, float m) {
	Vector2 temp;
	temp.x = v1.x * m;
	temp.y = v1.y * m;
	return temp;
}
Vector2 operator*(float m, Vector2& v1) {
	Vector2 temp;
	temp.x = v1.x * m;
	temp.y = v1.y * m;
	return temp;
}
Vector2 operator/(Vector2& v1, float m) {
	if (m == 0) {
		return v1;
	}
	else {
		Vector2 temp;
		temp.x = v1.x / m;
		temp.y = v1.y / m;
		return temp;
	}
}
Vector2& operator+=(Vector2& v1, const Vector2& v2) {
	v1.x = v1.x + v2.x;
	v1.y = v1.y + v2.y;
	return v1;
}
Vector2& operator-=(Vector2& v1, const Vector2& v2) {
	v1.x = v1.x - v2.x;
	v1.y = v1.y - v2.y;
	return v1;
}
Vector2& operator*=(Vector2& v1, float m) {
	v1.x = v1.x * m;
	v1.y = v1.y * m;
	return v1;
}
Vector2& operator/=(Vector2& v1, float m) {
	if (m == 0) {
		return v1;
	}
	else {
		v1.x = v1.x / m;
		v1.y = v1.y / m;
		return v1;
	}
}