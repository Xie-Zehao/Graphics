#include"Vector3.h"

Vector3::Vector3() {}
Vector3::Vector3(float x, float y, float z) :x(x), y(y), z(z) {}
Vector3::Vector3(const Vector3& v1) : x(v1.x), y(v1.y), z(v1.z) {}
Vector3::~Vector3() {}
Vector3 Vector3::operator=(const Vector3& v1)
{
	Vector3 temp;
	temp.x = v1.x;
	temp.y = v1.y;
	temp.z = v1.z;
	temp.w = v1.w;
	return temp;
	// TODO: �ڴ˴����� return ���
}
void Vector3::Normalize() {
	float result;
	result = (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	this->x = this->x / result;
	this->y = this->y / result;
	this->z = this->z / result;
}

//���
Vector3 Vector3::Cross(Vector3& lhs, Vector3& rhs) {
	Vector3 temp;
	temp.x = lhs.y * rhs.z - rhs.y * lhs.z;
	temp.y = lhs.z * rhs.x - rhs.z * lhs.y;
	temp.z = lhs.x * rhs.y - rhs.x * lhs.y;
	return temp;
}
//���
float Vector3::Dot(Vector3& lhs, Vector3& rhs) {
	float result;
	result = lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	return result;
}

//���Բ�ֵ
Vector3 Lerp(Vector3& from, Vector3& to, float t) {
	Vector3 temp;
	temp.x = from.x + t * (to.x - from.x);
	temp.y = from.y + t * (to.y - from.y);
	temp.z = from.z + t * (to.z - from.z);
	return temp;
}
//�������
Vector3 operator+(Vector3& v1, Vector3& v2) {
	Vector3 temp;
	temp.x = v1.x + v2.x;
	temp.y = v1.y + v2.y;
	temp.z = v1.z + v2.z;
	return temp;
}
//�������
Vector3& operator-(Vector3& v1, Vector3& v2) {
	Vector3 temp;
	temp.x = v1.x - v2.x;
	temp.y = v1.y - v2.y;
	temp.z = v1.z - v2.z;
	temp.w = v1.w - v2.w;
	return temp;
}

//���ص�ˣ����� * ������
float operator*(Vector3& v1, Vector3& v2) {
	float result;
	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return result;
}
//�������ˣ��� * ������
Vector3 operator*(float a, Vector3& b) {
	Vector3 temp;
	temp.x = a * b.x;
	temp.y = a * b.y;
	temp.z = a * b.z;
	return temp;
}
//�������ˣ����� * ����
Vector3 operator*(Vector3& b, float a) {
	Vector3 temp;
	temp.x = a * b.x;
	temp.y = a * b.y;
	temp.z = a * b.z;
	return temp;
}
//���س��������� / ����
Vector3 operator/(Vector3& b, float a) {
	Vector3 temp;
	temp.x = b.x / a;
	temp.y = b.y / a;
	temp.z = b.z / a;
	return temp;
}
Vector3 operator-(Vector3& v1)
{
	Vector3 temp;
	temp.x = 0 - v1.x;
	temp.y = 0 - v1.y;
	temp.z = 0 - v1.z;
	return temp;
}
//���ص��������
bool operator==(Vector3& lhs, Vector3& rhs) {
	bool flag = false;
	if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z) {
		flag = true;
	}
	return flag;
}
//���ز����������
bool operator!=(Vector3& lhs, Vector3& rhs) {
	bool flag = true;
	if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z) {
		flag = false;
	}
	return flag;
}