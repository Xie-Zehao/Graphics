#pragma once 
#include "Vector2.h"
#include "Matrix.h"

class MatrixV2 :public Matrix{
public:
	Vector2* v2 = NULL;//��Ҫ��ͼ�εĵ�������а󶨣���Ȼ���ڴ����鷳
	int v2number = 0;//ͼ�ε�ĸ���

	void setMatrix(Vector2* a, int b);//��λ��������ʼ��
	void MultiplyMatrix();//�������
	void Scale(float x, float y);//����
	void Rotation(float beta);//��ת
	void Translation(float x, float y);//ƽ��
};