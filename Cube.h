#pragma once
#include "Face.h"
#include "Vector3.h"

//���Ǹ���������
class Cube {
public:
	//1���յĹ��캯��
	Cube();
	//2���������캯��
	Cube(const Cube& c1);
	//3����������
	~Cube();
	//4�����㸳ֵ,��һ���������
	void readVector3(Vector3* pvector);
	//5�����渳ֵ����һ���������
	void readFace(Face* pface);

	//��������������꣺
	Vector3 Vmodel[8];
	//������������
	Vector3 Vworld[8];
	//����6����
	Face f[6];
};