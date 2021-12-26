#pragma once
#include"Vector2.h"
#include"Vector3.h"
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
class Matrix {
public:
	Matrix();
	~Matrix();//析构函数
	void Identity();//单位矩阵初始化
	void setMatrix(Vector2* a, int b);//二位顶点矩阵初始化
	void MultiplyMatrix2();//矩阵相乘
	void Translate(float x, float y);//平移变换
	void Scale(float x, float y);//缩放变换
	void Scale(float sx, float sy, Vector2 v2);//对于任意点缩放变换
	void Rotate(float beta);//旋转变换
	void Rotate(float beta, Vector2 v2);//对于任意点旋转变换
	void Reflect0();//二阶对原点反射变换
	void ReflectX();//二阶对X轴反射变换
	void ReflectY();//二阶对Y轴反射变换
	void Shear(float a, float b);//错切变换

	void setMatrix(Vector3* a, int b);//三维顶点数组初始化
	void Translate(float x, float y, float z);//位移变换
	void Scale(float x, float y, float z);//比例变换
	void Scale(float sx, float sy, float sz, Vector3 v3);//对于任意点的比例变换	
	void RotateX(float beta);//绕X轴旋转变换
	void RotateY(float beta);//绕Y轴旋转变换
	void RotateZ(float beta);//绕Z轴旋转变换
	void RotateX(float beta, Vector3 p);//相对于任意点的绕X轴旋转变换
	void RotateY(float beta, Vector3 p);//相对于任意点的绕Y轴旋转变换
	void RotateZ(float beta, Vector3 p);//相对于任意点的绕Z轴旋转变换
	void ReflectX3(void);//关于X轴反射变换
	void ReflectY3(void);//关于Y轴反射变换
	void ReflectZ3(void);//关于Z轴反射变换
	void ReflectXOY(void);//关于XOY面反射变换
	void ReflectYOZ(void);//关于YOZ面反射变换
	void ReflectZOX(void);//关于ZOX面反射变换
	void ShearX(float b, float c);//沿X方向错切变换
	void ShearY(float d, float f);//沿Y方向错切变换
	void ShearZ(float g, float h);//沿Z方向错切边换
	void OLJ(float x, float y, float z);//欧拉角
	void MultiplyMatrix3();//矩阵相乘

	void BiasProjection(float alpha, float beta);//斜投影
	/*关于错切变换
	* X = x + ay	= 1,a   x
	* Y = y + bx	= b,1	y
	*/
	void ToString();
	void Locationtransform(float x1, float x2);
	float T[4][4];//给一个4x4的矩阵，用多少拿多少就行，给够
	Vector2* v2 = NULL;//需要和图形的点数组进行绑定，不然后期处理麻烦
	Vector3* v3 = NULL;//需要和图形的点数组进行绑定，不然后期处理麻烦
	int v2number = 0;//图形点的个数
	int v3number = 0;//图形点的个数
};