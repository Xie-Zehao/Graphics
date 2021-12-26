#pragma once
#include"Vector2.h"
#include"Vector3.h"
using namespace std;
/*�������һ�������࣬�ǶԶ�ά���������������߱任��
* ��ά������������Դ����У���һ����ά����������һ��������꣩
* ����һ���㣨x1,y1���������Դ����б�ʾΪ��x1,y1,1��
* �����任�������Ϊ��x2,y2��,�����Դ����б�ʾΪ��x2,y2,1��
* ����任�Ĺ��̾��Ǳ���Vector2Transform
* һ���������任�����Դ�����ʾ���£�
*	a b c		x1		x2
*	d e f	*	y1	=	y2
*	g h i		1		1
* ���ǣ���ͼ��ѧ�У�һ��ͼ�β�ֹһ����
* ������Ҫ��Ҫһ�������飬���ߴ���ʾ���£�
* 	a b c		x1,x2,x3		x5,x6,x7
*	d e f	*	y1,y2,y3	=	y5,y6,y7
*	g h i		 1, 1 ,1		 1, 1, 1
* �任����ĵ�һ���ǹ���X�ģ��ڶ����ǹ���Y�ģ�
*/
class Matrix {
public:
	Matrix();
	~Matrix();//��������
	void Identity();//��λ�����ʼ��
	void setMatrix(Vector2* a, int b);//��λ��������ʼ��
	void MultiplyMatrix2();//�������
	void Translate(float x, float y);//ƽ�Ʊ任
	void Scale(float x, float y);//���ű任
	void Scale(float sx, float sy, Vector2 v2);//������������ű任
	void Rotate(float beta);//��ת�任
	void Rotate(float beta, Vector2 v2);//�����������ת�任
	void Reflect0();//���׶�ԭ�㷴��任
	void ReflectX();//���׶�X�ᷴ��任
	void ReflectY();//���׶�Y�ᷴ��任
	void Shear(float a, float b);//���б任

	void setMatrix(Vector3* a, int b);//��ά���������ʼ��
	void Translate(float x, float y, float z);//λ�Ʊ任
	void Scale(float x, float y, float z);//�����任
	void Scale(float sx, float sy, float sz, Vector3 v3);//���������ı����任	
	void RotateX(float beta);//��X����ת�任
	void RotateY(float beta);//��Y����ת�任
	void RotateZ(float beta);//��Z����ת�任
	void RotateX(float beta, Vector3 p);//�������������X����ת�任
	void RotateY(float beta, Vector3 p);//�������������Y����ת�任
	void RotateZ(float beta, Vector3 p);//�������������Z����ת�任
	void ReflectX3(void);//����X�ᷴ��任
	void ReflectY3(void);//����Y�ᷴ��任
	void ReflectZ3(void);//����Z�ᷴ��任
	void ReflectXOY(void);//����XOY�淴��任
	void ReflectYOZ(void);//����YOZ�淴��任
	void ReflectZOX(void);//����ZOX�淴��任
	void ShearX(float b, float c);//��X������б任
	void ShearY(float d, float f);//��Y������б任
	void ShearZ(float g, float h);//��Z������б߻�
	void OLJ(float x, float y, float z);//ŷ����
	void MultiplyMatrix3();//�������

	void BiasProjection(float alpha, float beta);//бͶӰ
	/*���ڴ��б任
	* X = x + ay	= 1,a   x
	* Y = y + bx	= b,1	y
	*/
	void ToString();
	void Locationtransform(float x1, float x2);
	float T[4][4];//��һ��4x4�ľ����ö����ö��پ��У�����
	Vector2* v2 = NULL;//��Ҫ��ͼ�εĵ�������а󶨣���Ȼ���ڴ����鷳
	Vector3* v3 = NULL;//��Ҫ��ͼ�εĵ�������а󶨣���Ȼ���ڴ����鷳
	int v2number = 0;//ͼ�ε�ĸ���
	int v3number = 0;//ͼ�ε�ĸ���
};