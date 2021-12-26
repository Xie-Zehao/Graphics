#include<stdio.h>
#include"Matrix.h"
#define _USE_MATH_DEFINES // 这个是PI的定义
#include<math.h>

using namespace std;
/*这个类是一个矩阵类，是对二维齐次坐标点类进行左边变换的
* 二维齐次坐标在线性代数中，是一个三维列向量（加一个齐次坐标）
* 所以一个点（x1,y1），在线性代数中表示为（x1,y1,1）
* 这个点变换后的坐标为（x2,y2）,在线性代数中表示为（x2,y2,1）
* 这个变换的过程就是本类Vector2Transform
* 一个点的坐标变换用线性代数表示如下：
*	a b c		x1		x2
*	d e f	*	y1	=	y2
*	g h i		1		1
* 但是，在图形学中，一个图形不止一个点
* 所以需要需要一个点数组，用线代表示如下：
* 	a b c		x1,x2,x3		x5,x6,x7
*	d e f	*	y1,y2,y3	=	y5,y6,y7
*	g h i		 1, 1 ,1		 1, 1, 1
* 变换矩阵的第一行是关于X的，第二行是关于Y的；
*/
	Matrix::Matrix() {//无参构造函数，全部初始化为1
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				T[i][j] = 1;
			}
		}
	}
	Matrix::~Matrix() {}//析构函数
	void Matrix::Identity() { //直接简单粗暴，赋值单位矩阵
		T[0][0] = 1; T[0][1] = 0; T[0][2] = 0; T[0][3] = 0;
		T[1][0] = 0; T[1][1] = 1; T[1][2] = 0; T[1][3] = 0;
		T[2][0] = 0; T[2][1] = 0; T[2][2] = 1; T[2][3] = 0;
		T[3][0] = 0; T[3][1] = 0; T[3][2] = 0; T[3][3] = 1;
	}
	void Matrix::setMatrix(Vector2* a, int b) {//需要传入二维点的个数和数组名字来进行绑定
		this->v2 = a;
		this->v2number = b;
	}
	void Matrix::setMatrix(Vector3* a, int b) {//需要传入三维点的个数和数组名字来进行绑定
		this->v3 = a;
		this->v3number = b;
	}
	void Matrix::MultiplyMatrix2() {//二维点的变换
		for (int i = 0; i < v2number; i++) {
			v2[i].x = T[0][0] * v2[i].x + T[0][1] * v2[i].y + T[0][2] * v2[i].w;
			v2[i].y = T[1][0] * v2[i].x + T[1][1] * v2[i].y + T[1][2] * v2[i].w;
			v2[i].w = T[2][0] * v2[i].x + T[2][1] * v2[i].y + T[2][2] * v2[i].w;
		}
	}
	void Matrix::MultiplyMatrix3() {//三维点的变换
		for (int i = 0; i < v3number; i++) {
			v3[i].x = T[0][0] * v3[i].x + T[0][1] * v3[i].y + T[0][2] * v3[i].z + T[0][3] * v3[i].w;
			v3[i].y = T[1][0] * v3[i].x + T[1][1] * v3[i].y + T[1][2] * v3[i].z + T[1][3] * v3[i].w;
			v3[i].z = T[2][0] * v3[i].x + T[2][1] * v3[i].y + T[2][2] * v3[i].z + T[2][3] * v3[i].w;
			v3[i].w = T[3][0] * v3[i].x + T[3][1] * v3[i].y + T[3][2] * v3[i].z + T[3][3] * v3[i].w;
		}
	}
	void Matrix::Translate(float x, float y) {//平移变换
		Identity(); // 直接初始化一个单位矩阵
		T[0][2] = x;
		T[1][2] = y;
		MultiplyMatrix2();
	}

	void Matrix::Scale(float x, float y) {//比例变换
		Identity(); // 直接初始化一个单位矩阵
		T[0][0] = x;
		T[1][1] = y;
		MultiplyMatrix2();
	}

	void Matrix::Scale(float sx, float sy, Vector2 v2) {//相对于v2的整体变换
		Translate(-v2.x, -v2.y);
		Scale(sx, sy);
		Translate(v2.x, v2.y);
	}

	void Matrix::Rotate(float beta) {//旋转变换  180°= PI；1°= PI/180；默认是顺时针转动，转动角度为beta°
		Identity();
		T[0][0] = cos(beta / 180 * M_PI); T[0][1] = -sin(beta / 180 * M_PI);
		T[1][0] = sin(beta / 180 * M_PI); T[1][1] = cos(beta / 180 * M_PI);
		MultiplyMatrix2();
	}
	void Matrix::Rotate(float beta, Vector2 v2) {//旋转变换  180°= PI；1°= PI/180；默认是顺时针转动，转动角度为beta°
		Translate(-v2.x, -v2.y);
		Rotate(beta);
		Translate(v2.x, v2.y);
	}



	void Matrix::Reflect0() {//关于原点进行反射
		Identity();
		T[0][0] = -1;
		T[1][1] = -1;
		MultiplyMatrix2();
	}
	void Matrix::ReflectX() {//关于X轴进行反射
		Identity();
		T[0][0] = 1;
		T[1][1] = -1;
		MultiplyMatrix2();
	}
	void Matrix::ReflectY() {//关于Y轴进行反射

		T[0][0] = -1;
		T[1][1] = 1;
		MultiplyMatrix2();
	}
	/*关于错切变换
	* X = x + ay	= 1,a   x
	* Y = y + bx	= b,1	y
	*/
	void Matrix::Shear(float a, float b) {
		Identity();
		T[0][1] = a;
		T[1][0] = b;
		MultiplyMatrix2();
	}
	void Matrix::ToString() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << " " << T[i][j] << " ";
			}
			cout << endl;
		}
	}
	void Matrix::Locationtransform(float x1, float x2) {//坐标变换
		Identity();//第一步还是初始化矩阵
		T[2][0] = -x1;
		T[2][1] = -x2;
		MultiplyMatrix2();
	}

	/*这里开始就是三阶矩阵的东西
	*/
	void Matrix::Scale(float x, float y, float z) {//比例变换
		Identity(); // 直接初始化一个单位矩阵
		T[0][0] = x;
		T[1][1] = y;
		T[2][2] = z;
		MultiplyMatrix3();
	}
	void Matrix::Scale(float sx, float sy, float sz, Vector3 v3) {//相对于v3的整体变换
		Translate(-v3.x, -v3.y, -v3.z);
		Scale(sx, sy, sz);
		Translate(v3.x, v3.y, v3.z);
	}
	void Matrix::Translate(float x, float y, float z) {//平移变换
		Identity(); // 直接初始化一个单位矩阵
		T[0][3] = x;
		T[1][3] = y;
		T[2][3] = z;
		MultiplyMatrix3();
	}
	void Matrix::RotateX(float beta) {
		Identity();
		T[1][1] = cos(beta / 180 * M_PI); T[1][2] = -sin(beta / 180 * M_PI);
		T[2][1] = sin(beta / 180 * M_PI); T[2][2] = cos(beta / 180 * M_PI);
		MultiplyMatrix3();
	}
	void Matrix::RotateY(float beta) {
		Identity();
		T[0][0] = cos(beta / 180 * M_PI); T[0][2] = sin(beta / 180 * M_PI);
		T[2][0] = -sin(beta / 180 * M_PI); T[2][2] = cos(beta / 180 * M_PI);
		MultiplyMatrix3();
	}
	void Matrix::RotateZ(float beta) {
		Identity();
		T[0][0] = cos(beta / 180 * M_PI); T[0][1] = -sin(beta / 180 * M_PI);
		T[1][0] = sin(beta / 180 * M_PI); T[1][1] = cos(beta / 180 * M_PI);
		MultiplyMatrix3();
	}
	void Matrix::RotateX(float beta, Vector3 p)
	{
		Translate(-p.x, -p.y, -p.z);
		RotateX(beta);
		Translate(p.x, p.y, p.z);
	}
	void Matrix::RotateY(float beta, Vector3 p)
	{
		Translate(-p.x, -p.y, -p.z);
		RotateY(beta);
		Translate(p.x, p.y, p.z);
	}
	void Matrix::RotateZ(float beta, Vector3 p)
	{
		Translate(-p.x, -p.y, -p.z);
		RotateZ(beta);
		Translate(p.x, p.y, p.z);
	}
	void Matrix::ReflectX3(void)
	{
		Identity();
		T[1][1] = -1; T[2][2] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ReflectY3(void)
	{
		Identity();
		T[0][0] = -1; T[2][2] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ReflectZ3(void)
	{
		Identity();
		T[0][0] = -1; T[1][1] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ReflectXOY(void)
	{
		Identity();
		T[2][2] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ReflectYOZ(void)
	{
		Identity();
		T[0][0] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ReflectZOX(void)
	{
		Identity();
		T[1][1] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ShearX(float b, float c)
	{
		Identity();
		T[0][1] = b; T[0][2] = c;
		MultiplyMatrix3();
	}
	void Matrix::ShearY(float d, float f)
	{
		Identity();
		T[1][0] = d; T[1][2] = f;
		MultiplyMatrix3();
	}
	void Matrix::ShearZ(float g, float h)
	{
		Identity();
		T[2][0] = g; T[2][1] = h;
		MultiplyMatrix3();
	}
	void Matrix::OLJ(float x, float y, float z)
	{
		Identity();
		T[0][0] = cos(y / 180 * M_PI)*cos(z / 180 * M_PI);	T[0][1]=cos(z / 180 * M_PI)*sin(x / 180 * M_PI)*sin(y / 180 * M_PI)-cos(x / 180 * M_PI)*sin(z / 180 * M_PI);	T[0][2]=sin(x / 180 * M_PI)*sin(z / 180 * M_PI)+cos(x / 180 * M_PI)*cos(z / 180 * M_PI)*sin(y / 180 * M_PI);
		T[1][0] =cos(y / 180 * M_PI)*sin(z / 180 * M_PI);	T[1][1]=cos(x / 180 * M_PI)*cos(z / 180 * M_PI)+sin(x / 180 * M_PI)*sin(y / 180 * M_PI)*sin(z / 180 * M_PI);	T[1][2]=cos(x / 180 * M_PI)*sin(y / 180 * M_PI)*sin(z / 180 * M_PI)-cos(z / 180 * M_PI)*sin(z / 180 * M_PI);
		T[2][0] =-sin(y / 180 * M_PI);						T[2][1]=cos(y / 180 * M_PI)*sin(x / 180 * M_PI);																T[2][2]=cos(x / 180 * M_PI)*cos(y / 180 * M_PI);
		MultiplyMatrix3();
	}
	void Matrix::BiasProjection(float alpha,float beta) {//开始进行斜投影
		Identity();//第一步是初始化矩阵
		T[0][2] = -(cos(alpha / 180 * M_PI) / sin(alpha / 180 * M_PI))*cos(beta/ 180 * M_PI);
		T[1][2] = -(cos(alpha / 180 * M_PI) / sin(alpha / 180 * M_PI))*sin(beta/ 180 * M_PI);
		MultiplyMatrix3();
	}

