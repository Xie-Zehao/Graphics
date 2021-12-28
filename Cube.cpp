#include "Cube.h"

//1，空的构造函数
Cube:: Cube(){}
//2，拷贝构造函数
Cube::Cube(const Cube& c1) {
	for (int i = 0; i < 8; i++) {
		this->Vmodel[i] = c1.Vmodel[i];
	}
	for (int i = 0; i < 6; i++) {
		this->f[i] = c1.f[i];
	}
}
//3，析构函数
Cube::~Cube(){}
//4，给点赋值,传一个数组过来
void Cube::readVector3(Vector3 * pvector) {
	for (int i = 0; i < 8; i++) {
		Vmodel[i] = pvector[i];
	}
}
//5，给面赋值，传一个数组过来
void Cube::readFace(Face * pface) {
	for (int i = 0; i < 6; i++) {
		f[i] = pface[i];
	}
}

