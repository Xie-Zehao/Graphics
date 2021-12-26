#include "Screen_Matrix.h"
 Screen_Matrix::Screen_Matrix() {
	T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
	T[1][0] = 0; T[1][1] = 1; T[1][2] = 0;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
}

 void Screen_Matrix::SetMatrix(float dx,float dy, Vector2 v2)
 {
	 T[0][0] = 1/dx;	T[0][1] = 0;		T[0][2] = v2.x;
	 T[1][0] = 0;		T[1][1] = 1/dy;		T[1][2] = v2.y;
	 T[2][0] = 0;		T[2][1] = 0;		T[2][2] = 1;
 }

 Vector2 Screen_Matrix::Multiply(Vector2 v2)
 {
	 Vector2 temp;
	 temp.x = T[0][0] * v2.x + T[0][1] * v2.y + T[0][2] * v2.w;
	 temp.y = T[1][0] * v2.x + T[1][1] * v2.y + T[1][2] * v2.w;
	 temp.w = T[2][0] * v2.x + T[2][1] * v2.y + T[2][2] * v2.w;
	 return temp;
 }
