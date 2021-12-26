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
	// TODO: 在此处插入 return 语句
}
void Vector3::Scale(Vector3& scale) {
	this->x = this->x * scale.x;
	this->y = this->y * scale.y;
	this->z = this->z * scale.z;
}
Vector3 Vector3::Scale(Vector3& a, Vector3& b) {
	Vector3 temp;
	temp.x = a.x * b.x;
	temp.y = a.y * b.y;
	temp.z = a.z * b.z;
	return temp;
}
void Vector3::Normalize() {
	float result;
	result = (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	this->x = this->x / result;
	this->y = this->y / result;
	this->z = this->z / result;
}
void Vector3::ToString() {
	cout << "(" << this->x << "," << this->y << "," << this->z << ")" << endl;
}
void Vector3::ToString(string format) {
	cout << format << endl;
}
Vector3 Vector3::zero() {
	Vector3 temp;
	temp.x = 0;
	temp.y = 0;
	temp.z = 0;
	return temp;
}
Vector3 Vector3::one() {
	Vector3 temp;
	temp.x = 1;
	temp.y = 1;
	temp.z = 1;
	return temp;
}
//z轴，向前
Vector3 Vector3::forward() {
	Vector3 temp;
	temp.x = 0;
	temp.y = 0;
	temp.z = 1;
	return temp;
}
//y轴，向上
Vector3 Vector3::up() {
	Vector3 temp;
	temp.x = 0;
	temp.y = 1;
	temp.z = 0;
	return temp;
}
//x轴，向右
Vector3 Vector3::right() {
	Vector3 temp;
	temp.x = 1;
	temp.y = 0;
	temp.z = 0;
	return temp;
}
//直角规范化
Vector3 Vector3::OrthoNormalize(Vector3 normal, Vector3 tangent) {
	Vector3 temp;
	return temp;
}
Vector3  Vector3::OrthoNormalize(Vector3 normal, Vector3 tengent, Vector3 binormal) {
	Vector3 temp;
	return temp;
}
//移向
Vector3 Vector3::MoveTowards(Vector3 current, Vector3 target, float maxDistanceDelta) {
	Vector3 temp;
	return temp;
}
//转向
Vector3 Vector3::RotateWowards(Vector3 current, Vector3 target, float maxRadiansDelta, float maxMagnitudeDelta) {
	Vector3 temp;
	return temp;
}
//平滑阻尼
Vector3 Vector3::SmoothDamp(Vector3 current, Vector3 target, Vector3 currentVelocity, float smoothTime, float maxSpeed, float deltaTime) {
	Vector3 temp;
	return temp;
}
//叉乘
Vector3 Vector3::Cross(Vector3& lhs, Vector3& rhs) {
	Vector3 temp;
	temp.x = lhs.y * rhs.z - rhs.y * lhs.z;
	temp.y = lhs.z * rhs.x - rhs.z * lhs.y;
	temp.z = lhs.x * rhs.y - rhs.x * lhs.y;
	return temp;
}
//反射
Vector3 Vector3::Reflect(Vector3 inDirection, Vector3 inNormal) {
	Vector3 temp;
	return temp;
}
//点乘
float Vector3::Dot(Vector3& lhs, Vector3& rhs) {
	float result;
	result = lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	return result;
}
//投影
Vector3 Vector3::Project(Vector3& a, Vector3& b) {
	Vector3 temp;
	float result = a.x * b.x + a.y * b.y + a.z * b.z;// |a|*|b|cos(<a,b>) = a * b
	float blength = sqrt(pow(b.x, 2) + pow(b.y, 2) + pow(b.z, 2));// |b|
	float alengthcosab = result / blength;// |a|*cos(<a,b>) = a*b/(|b|);
	//temp /( |a|*cos(<a,b>) ) = b/|b|   ===>>   temp = (b/|b|)*( |a|*cos(<a,b>) )
	temp.x = (b.x / blength) * (alengthcosab);
	temp.y = (b.y / blength) * (alengthcosab);
	temp.z = (b.z / blength) * (alengthcosab);
	return temp;
}
//返回最小组件组成的向量
Vector3 Vector3::Min(Vector3& lhs, Vector3& rhs) {
	Vector3 temp;
	if (lhs.x > rhs.x) {
		temp.x = rhs.x;
	}
	else {
		temp.x = lhs.x;
	}
	if (lhs.y > rhs.y) {
		temp.y = rhs.y;
	}
	else {
		temp.y = lhs.y;
	}
	if (lhs.z > rhs.z) {
		temp.z = rhs.z;
	}
	else {
		temp.z = lhs.z;
	}
	return temp;
}
//返回最大组件组成的向量
Vector3 Vector3::Max(Vector3& lhs, Vector3& rhs) {
	Vector3 temp;
	if (lhs.x < rhs.x) {
		temp.x = rhs.x;
	}
	else {
		temp.x = lhs.x;
	}
	if (lhs.y < rhs.y) {
		temp.y = rhs.y;
	}
	else {
		temp.y = lhs.y;
	}
	if (lhs.z < rhs.z) {
		temp.z = rhs.z;
	}
	else {
		temp.z = lhs.z;
	}
	return temp;
}


//线性插值
Vector3 Lerp(Vector3& from, Vector3& to, float t) {
	Vector3 temp;
	temp.x = from.x + t * (to.x - from.x);
	temp.y = from.y + t * (to.y - from.y);
	temp.z = from.z + t * (to.z - from.z);
	return temp;
}
//重载相加
Vector3 operator+(Vector3& v1, Vector3& v2) {
	Vector3 temp;
	temp.x = v1.x + v2.x;
	temp.y = v1.y + v2.y;
	temp.z = v1.z + v2.z;
	return temp;
}
//重载相减
Vector3& operator-(Vector3& v1, Vector3& v2) {
	Vector3 temp;
	temp.x = v1.x - v2.x;
	temp.y = v1.y - v2.y;
	temp.z = v1.z - v2.z;
	temp.w = v1.w - v2.w;
	return temp;
}

//重载点乘（向量 * 向量）
float operator*(Vector3& v1, Vector3& v2) {
	float result;
	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return result;
}
//重载数乘（数 * 向量）
Vector3 operator*(float a, Vector3& b) {
	Vector3 temp;
	temp.x = a * b.x;
	temp.y = a * b.y;
	temp.z = a * b.z;
	return temp;
}
//重载数乘（向量 * 数）
Vector3 operator*(Vector3& b, float a) {
	Vector3 temp;
	temp.x = a * b.x;
	temp.y = a * b.y;
	temp.z = a * b.z;
	return temp;
}
//重载除法（向量 / 数）
Vector3 operator/(Vector3& b, float a) {
	Vector3 temp;
	temp.x = b.x / a;
	temp.y = b.y / a;
	temp.z = b.z / a;
	return temp;
}
//重载等于运算符
bool operator==(Vector3& lhs, Vector3& rhs) {
	bool flag = false;
	if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z) {
		flag = true;
	}
	return flag;
}
//重载不等于运算符
bool operator!=(Vector3& lhs, Vector3& rhs) {
	bool flag = true;
	if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z) {
		flag = false;
	}
	return flag;
}