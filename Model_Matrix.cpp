#include "Model_Matrix.h"
#define _USE_MATH_DEFINES // 这个是PI的定义
#include<math.h>

void Model_Matrix::ChangModelToWorld(float dx, float dy, float dz, float x, float y, float z, float sx, float sy, float sz)
{
	Translate(dx, dy, dz);
	OLJ(x, y, z);
	Scale(sx, sy, sz);
}
