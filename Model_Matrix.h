#pragma once
#include"Vector3.h"
#include "Matrix.h"
class Model_Matrix:public Matrix{
public:
	void ChangModelToWorld(float dx, float dy, float dz, float x, float y, float z, float sx, float sy, float sz);
};