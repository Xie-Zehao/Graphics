#include "Projection_Matrix.h"

Projection_Matrix::Projection_Matrix(float x) {
    T[0][0] = x; T[0][1] = 0; T[0][2] = 0; T[0][3] = 0;
    T[1][0] = 0; T[1][1] = x; T[1][2] = 0; T[1][3] = 0;
    T[2][0] = 0; T[2][1] = 0; T[2][2] = 1; T[2][3] = 0;
}

Vector2 Projection_Matrix::Multiply(Vector3 V3)
{
    Vector2 temp;
    temp.x = T[0][0] * V3.x + T[0][1] * V3.y + T[0][2] * V3.z + T[0][3] * V3.w;
    temp.y = T[1][0] * V3.x + T[1][1] * V3.y + T[1][2] * V3.z + T[1][3] * V3.w;
    temp.w = T[2][0] * V3.x + T[2][1] * V3.y + T[2][2] * V3.z + T[2][3] * V3.w;
    return temp;
}
