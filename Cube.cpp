#include "Cube.h"

//1���յĹ��캯��
Cube:: Cube(){}
//2���������캯��
Cube::Cube(const Cube& c1) {
	for (int i = 0; i < 8; i++) {
		this->Vmodel[i] = c1.Vmodel[i];
	}
	for (int i = 0; i < 6; i++) {
		this->f[i] = c1.f[i];
	}
}
//3����������
Cube::~Cube(){}
//4�����㸳ֵ,��һ���������
void Cube::readVector3(Vector3 * pvector) {
	for (int i = 0; i < 8; i++) {
		Vmodel[i] = pvector[i];
	}
}
//5�����渳ֵ����һ���������
void Cube::readFace(Face * pface) {
	for (int i = 0; i < 6; i++) {
		f[i] = pface[i];
	}
}

