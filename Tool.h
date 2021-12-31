#pragma once
#include "Vector3.h"
#include "Triangle.h"
#include <windows.h>
class Line {
public:
	Line();//�յĹ��캯��
	~Line();//�յ���������
	Line(Line& l);//�������캯��

	void MoveTo(HDC &hdc,Vector3 &v3);
	void MoveTo(HDC &hdc, int x1,int y1);
	void LineTo(HDC &hdc, Vector3 &v3);
	
	void LineTo(HDC &hdc, int x1, int y1);
	Vector3 p0; //������ʾ�ҵ���ʼ��
	Vector3 p1;//������ʾ�ҵ���һ����

	//��Ҫһ�����ߵĺ�����Ҫ����������
	void Draw_Line(HDC& hdc, Vector3& begin ,Vector3& v3);
	//��Ҫһ�����߿�ĺ�����Ҫ��������ģ�ͣ����û��ߵĺ���
	void rasterize_wireframe(HDC& hdc, Triangle& t);
};

