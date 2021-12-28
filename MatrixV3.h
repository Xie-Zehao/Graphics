#pragma once
#include "Vector3.h"
#include "Matrix.h"

class MatrixV3 :public Matrix {
public:
	Vector3* v3 = NULL;//��Ҫ��ͼ�εĵ�������а󶨣���Ȼ���ڴ����鷳
	int v3number = 0;//ͼ�ε�ĸ���

	void setMatrix(Vector3* a, int b);//��ά���������ʼ��
	void MultiplyMatrix();//�������
	void Scale(double x, double y, double z);//����
	void Rotation_About_X(double alpha);//��X����ת
	void Rotation_About_Y(double beta);//��Y����ת
	void Rotation_About_Z(double gamma);//��Z����ת
	void Rotation(double alpha, double beta, double gamma);//ŷ����
	void Translation(double x, double y,double z);//ƽ��
};