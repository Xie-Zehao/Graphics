#pragma once
#include "Vector3.h"
#include "Matrix.h"

class MatrixV3_Model :public Matrix {
public:
	Vector3* v3 = NULL;//��������
	int v3number =0 ;//������¼����������
	void Scale(float x, float y, float z);//����
	void Rotation_About_X(float alpha);//��X����ת
	void Rotation_About_Y(float beta);//��Y����ת
	void Rotation_About_Z(float gamma);//��Z����ת
	void Rotation(float alpha, float beta, float gamma);//ŷ����
	void Translation(float x, float y,float z);//ƽ��
};