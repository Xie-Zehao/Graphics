//������¼���������֮��Ĺ�ϵ���������Ϊ��֮���topo�ṹ
#include "Face.h"

Face::Face() {
	number = 0;
	for (int i = 0; i < 4; i++) {
		index[i] = 0;
	}
}
Face::~Face(){}