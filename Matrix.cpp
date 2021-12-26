#include<stdio.h>
#include"Matrix.h"
#define _USE_MATH_DEFINES // �����PI�Ķ���
#include<math.h>

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
	Matrix::Matrix() {//�޲ι��캯����ȫ����ʼ��Ϊ1
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				T[i][j] = 1;
			}
		}
	}
	Matrix::~Matrix() {}//��������
	void Matrix::Identity() { //ֱ�Ӽ򵥴ֱ�����ֵ��λ����
		T[0][0] = 1; T[0][1] = 0; T[0][2] = 0; T[0][3] = 0;
		T[1][0] = 0; T[1][1] = 1; T[1][2] = 0; T[1][3] = 0;
		T[2][0] = 0; T[2][1] = 0; T[2][2] = 1; T[2][3] = 0;
		T[3][0] = 0; T[3][1] = 0; T[3][2] = 0; T[3][3] = 1;
	}
	void Matrix::setMatrix(Vector2* a, int b) {//��Ҫ�����ά��ĸ������������������а�
		this->v2 = a;
		this->v2number = b;
	}
	void Matrix::setMatrix(Vector3* a, int b) {//��Ҫ������ά��ĸ������������������а�
		this->v3 = a;
		this->v3number = b;
	}
	void Matrix::MultiplyMatrix2() {//��ά��ı任
		for (int i = 0; i < v2number; i++) {
			v2[i].x = T[0][0] * v2[i].x + T[0][1] * v2[i].y + T[0][2] * v2[i].w;
			v2[i].y = T[1][0] * v2[i].x + T[1][1] * v2[i].y + T[1][2] * v2[i].w;
			v2[i].w = T[2][0] * v2[i].x + T[2][1] * v2[i].y + T[2][2] * v2[i].w;
		}
	}
	void Matrix::MultiplyMatrix3() {//��ά��ı任
		for (int i = 0; i < v3number; i++) {
			v3[i].x = T[0][0] * v3[i].x + T[0][1] * v3[i].y + T[0][2] * v3[i].z + T[0][3] * v3[i].w;
			v3[i].y = T[1][0] * v3[i].x + T[1][1] * v3[i].y + T[1][2] * v3[i].z + T[1][3] * v3[i].w;
			v3[i].z = T[2][0] * v3[i].x + T[2][1] * v3[i].y + T[2][2] * v3[i].z + T[2][3] * v3[i].w;
			v3[i].w = T[3][0] * v3[i].x + T[3][1] * v3[i].y + T[3][2] * v3[i].z + T[3][3] * v3[i].w;
		}
	}
	void Matrix::Translate(float x, float y) {//ƽ�Ʊ任
		Identity(); // ֱ�ӳ�ʼ��һ����λ����
		T[0][2] = x;
		T[1][2] = y;
		MultiplyMatrix2();
	}

	void Matrix::Scale(float x, float y) {//�����任
		Identity(); // ֱ�ӳ�ʼ��һ����λ����
		T[0][0] = x;
		T[1][1] = y;
		MultiplyMatrix2();
	}

	void Matrix::Scale(float sx, float sy, Vector2 v2) {//�����v2������任
		Translate(-v2.x, -v2.y);
		Scale(sx, sy);
		Translate(v2.x, v2.y);
	}

	void Matrix::Rotate(float beta) {//��ת�任  180��= PI��1��= PI/180��Ĭ����˳ʱ��ת����ת���Ƕ�Ϊbeta��
		Identity();
		T[0][0] = cos(beta / 180 * M_PI); T[0][1] = -sin(beta / 180 * M_PI);
		T[1][0] = sin(beta / 180 * M_PI); T[1][1] = cos(beta / 180 * M_PI);
		MultiplyMatrix2();
	}
	void Matrix::Rotate(float beta, Vector2 v2) {//��ת�任  180��= PI��1��= PI/180��Ĭ����˳ʱ��ת����ת���Ƕ�Ϊbeta��
		Translate(-v2.x, -v2.y);
		Rotate(beta);
		Translate(v2.x, v2.y);
	}



	void Matrix::Reflect0() {//����ԭ����з���
		Identity();
		T[0][0] = -1;
		T[1][1] = -1;
		MultiplyMatrix2();
	}
	void Matrix::ReflectX() {//����X����з���
		Identity();
		T[0][0] = 1;
		T[1][1] = -1;
		MultiplyMatrix2();
	}
	void Matrix::ReflectY() {//����Y����з���

		T[0][0] = -1;
		T[1][1] = 1;
		MultiplyMatrix2();
	}
	/*���ڴ��б任
	* X = x + ay	= 1,a   x
	* Y = y + bx	= b,1	y
	*/
	void Matrix::Shear(float a, float b) {
		Identity();
		T[0][1] = a;
		T[1][0] = b;
		MultiplyMatrix2();
	}
	void Matrix::ToString() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << " " << T[i][j] << " ";
			}
			cout << endl;
		}
	}
	void Matrix::Locationtransform(float x1, float x2) {//����任
		Identity();//��һ�����ǳ�ʼ������
		T[2][0] = -x1;
		T[2][1] = -x2;
		MultiplyMatrix2();
	}

	/*���￪ʼ�������׾���Ķ���
	*/
	void Matrix::Scale(float x, float y, float z) {//�����任
		Identity(); // ֱ�ӳ�ʼ��һ����λ����
		T[0][0] = x;
		T[1][1] = y;
		T[2][2] = z;
		MultiplyMatrix3();
	}
	void Matrix::Scale(float sx, float sy, float sz, Vector3 v3) {//�����v3������任
		Translate(-v3.x, -v3.y, -v3.z);
		Scale(sx, sy, sz);
		Translate(v3.x, v3.y, v3.z);
	}
	void Matrix::Translate(float x, float y, float z) {//ƽ�Ʊ任
		Identity(); // ֱ�ӳ�ʼ��һ����λ����
		T[0][3] = x;
		T[1][3] = y;
		T[2][3] = z;
		MultiplyMatrix3();
	}
	void Matrix::RotateX(float beta) {
		Identity();
		T[1][1] = cos(beta / 180 * M_PI); T[1][2] = -sin(beta / 180 * M_PI);
		T[2][1] = sin(beta / 180 * M_PI); T[2][2] = cos(beta / 180 * M_PI);
		MultiplyMatrix3();
	}
	void Matrix::RotateY(float beta) {
		Identity();
		T[0][0] = cos(beta / 180 * M_PI); T[0][2] = sin(beta / 180 * M_PI);
		T[2][0] = -sin(beta / 180 * M_PI); T[2][2] = cos(beta / 180 * M_PI);
		MultiplyMatrix3();
	}
	void Matrix::RotateZ(float beta) {
		Identity();
		T[0][0] = cos(beta / 180 * M_PI); T[0][1] = -sin(beta / 180 * M_PI);
		T[1][0] = sin(beta / 180 * M_PI); T[1][1] = cos(beta / 180 * M_PI);
		MultiplyMatrix3();
	}
	void Matrix::RotateX(float beta, Vector3 p)
	{
		Translate(-p.x, -p.y, -p.z);
		RotateX(beta);
		Translate(p.x, p.y, p.z);
	}
	void Matrix::RotateY(float beta, Vector3 p)
	{
		Translate(-p.x, -p.y, -p.z);
		RotateY(beta);
		Translate(p.x, p.y, p.z);
	}
	void Matrix::RotateZ(float beta, Vector3 p)
	{
		Translate(-p.x, -p.y, -p.z);
		RotateZ(beta);
		Translate(p.x, p.y, p.z);
	}
	void Matrix::ReflectX3(void)
	{
		Identity();
		T[1][1] = -1; T[2][2] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ReflectY3(void)
	{
		Identity();
		T[0][0] = -1; T[2][2] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ReflectZ3(void)
	{
		Identity();
		T[0][0] = -1; T[1][1] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ReflectXOY(void)
	{
		Identity();
		T[2][2] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ReflectYOZ(void)
	{
		Identity();
		T[0][0] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ReflectZOX(void)
	{
		Identity();
		T[1][1] = -1;
		MultiplyMatrix3();
	}
	void Matrix::ShearX(float b, float c)
	{
		Identity();
		T[0][1] = b; T[0][2] = c;
		MultiplyMatrix3();
	}
	void Matrix::ShearY(float d, float f)
	{
		Identity();
		T[1][0] = d; T[1][2] = f;
		MultiplyMatrix3();
	}
	void Matrix::ShearZ(float g, float h)
	{
		Identity();
		T[2][0] = g; T[2][1] = h;
		MultiplyMatrix3();
	}
	void Matrix::OLJ(float x, float y, float z)
	{
		Identity();
		T[0][0] = cos(y / 180 * M_PI)*cos(z / 180 * M_PI);	T[0][1]=cos(z / 180 * M_PI)*sin(x / 180 * M_PI)*sin(y / 180 * M_PI)-cos(x / 180 * M_PI)*sin(z / 180 * M_PI);	T[0][2]=sin(x / 180 * M_PI)*sin(z / 180 * M_PI)+cos(x / 180 * M_PI)*cos(z / 180 * M_PI)*sin(y / 180 * M_PI);
		T[1][0] =cos(y / 180 * M_PI)*sin(z / 180 * M_PI);	T[1][1]=cos(x / 180 * M_PI)*cos(z / 180 * M_PI)+sin(x / 180 * M_PI)*sin(y / 180 * M_PI)*sin(z / 180 * M_PI);	T[1][2]=cos(x / 180 * M_PI)*sin(y / 180 * M_PI)*sin(z / 180 * M_PI)-cos(z / 180 * M_PI)*sin(z / 180 * M_PI);
		T[2][0] =-sin(y / 180 * M_PI);						T[2][1]=cos(y / 180 * M_PI)*sin(x / 180 * M_PI);																T[2][2]=cos(x / 180 * M_PI)*cos(y / 180 * M_PI);
		MultiplyMatrix3();
	}
	void Matrix::BiasProjection(float alpha,float beta) {//��ʼ����бͶӰ
		Identity();//��һ���ǳ�ʼ������
		T[0][2] = -(cos(alpha / 180 * M_PI) / sin(alpha / 180 * M_PI))*cos(beta/ 180 * M_PI);
		T[1][2] = -(cos(alpha / 180 * M_PI) / sin(alpha / 180 * M_PI))*sin(beta/ 180 * M_PI);
		MultiplyMatrix3();
	}

