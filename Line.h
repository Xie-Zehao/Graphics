#pragma once
#include "Vector3.h"
#include <windows.h>
class Line {
public:
	Line();//�յĹ��캯��
	~Line();//�յ���������
	Line(Line& l);//�������캯��

	void MoveTo(HDC &hdc,Vector3 &v3);
	void MoveTo(HDC &hdc, int x1,int y1);
	void LineTo(HDC &hdc,Vector3 &v3);
	void LineTo(HDC &hdc, int x1, int y1);
	Vector3 p0; //������ʾ�ҵ���ʼ��
	Vector3 p1;//������ʾ�ҵ���һ����
};