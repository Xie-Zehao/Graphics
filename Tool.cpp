
//这个类记录了立方体点之间的关系，可以理解为点之间的topo结构
#include "Face.h"
#include "Tool.h"
Face::Face() {
	number = 0;
	for (int i = 0; i < 4; i++) {
		index[i] = 0;
	}
}
Face::~Face() {}



//for (int x = 0; x < xmax; ++x) {
//	for (int y = 0; Y < ymax; ++y) {
//		image[x][y] = inside(tri, x + 0.5, y + 0.5)
//	}
//}
