#include "MatrixV3_ViewPort.h"

MatrixV3_ViewPort::MatrixV3_ViewPort(double width, double height)
{
	T[0][0] = width / 2;	T[0][3] = width / 2;
	T[1][1] = height / 2;	T[1][3] = height / 2;
}
