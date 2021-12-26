#pragma once
#include "Vector3.h"
#include <windows.h>
class Line {
public:
	Line();//空的构造函数
	~Line();//空的析构函数
	Line(Line& l);//拷贝构造函数

	void MoveTo(HDC &hdc,Vector3 &v3);
	void MoveTo(HDC &hdc, int x1,int y1);
	void LineTo(HDC &hdc,Vector3 &v3);
	void LineTo(HDC &hdc, int x1, int y1);
	Vector3 p0; //这个点表示我的起始点
	Vector3 p1;//这个点表示我的下一个点
};