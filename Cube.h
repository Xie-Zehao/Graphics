#pragma once
#include "Face.h"
#include "Vector3.h"

//这是个立方体类
class Cube {
public:
	//1，空的构造函数
	Cube();
	//2，拷贝构造函数
	Cube(const Cube& c1);
	//3，析构函数
	~Cube();
	//4，给点赋值,传一个数组过来
	void readVector3(Vector3* pvector);
	//5，给面赋值，传一个数组过来
	void readFace(Face* pface);

	//最基本的物体坐标：
	Vector3 Vmodel[8];
	//变成世界坐标后：
	Vector3 Vworld[8];
	//包含6个面
	Face f[6];
};