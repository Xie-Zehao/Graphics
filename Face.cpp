//这个类记录了立方体点之间的关系，可以理解为点之间的topo结构
#include "Face.h"

Face::Face() {
	number = 0;
	for (int i = 0; i < 4; i++) {
		index[i] = 0;
	}
}
Face::~Face(){}