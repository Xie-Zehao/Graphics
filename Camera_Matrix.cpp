#include "Camera_Matrix.h"
#define _USE_MATH_DEFINES // 这个是PI的定义
#include<math.h>
void Camera_Matrix::ChangWorldToCamera(int x,int y,int z,Vector3 Cam)
{
	Identity();
	T[0][0] = cos(y / 180 * M_PI) * cos(z / 180 * M_PI);	T[0][1] = cos(z / 180 * M_PI) * sin(x / 180 * M_PI) * sin(y / 180 * M_PI) - cos(x / 180 * M_PI) * sin(z / 180 * M_PI);	T[0][2] = sin(x / 180 * M_PI) * sin(z / 180 * M_PI) + cos(x / 180 * M_PI) * cos(z / 180 * M_PI) * sin(y / 180 * M_PI);		T[0][3] = Cam.x;
	T[1][0] = cos(y / 180 * M_PI) * sin(z / 180 * M_PI);	T[1][1] = cos(x / 180 * M_PI) * cos(z / 180 * M_PI) + sin(x / 180 * M_PI) * sin(y / 180 * M_PI) * sin(z / 180 * M_PI);	T[1][2] = cos(x / 180 * M_PI) * sin(y / 180 * M_PI) * sin(z / 180 * M_PI) - cos(z / 180 * M_PI) * sin(z / 180 * M_PI);		T[1][3] = Cam.y;
	T[2][0] = -sin(y / 180 * M_PI);							T[2][1] = cos(y / 180 * M_PI) * sin(x / 180 * M_PI);																	T[2][2] = cos(x / 180 * M_PI) * cos(y / 180 * M_PI);																		T[2][3] = Cam.z;
	T[3][0] = 0;											T[3][1] = 0;																											T[3][2] = 0;																												T[3][3] = 1;
	MultiplyMatrix3();
}

void Camera_Matrix::ChangWorldToCamera(Vector3 Cam, Vector3 Cam_N_Direction, Vector3 Cam_V_UP, Vector3 Cam_U_Right)
{
	Identity();
	T[0][0] = Cam_U_Right.x;	T[0][1] = Cam_U_Right.y;	T[0][2] = Cam_U_Right.z;		T[0][3] = -v3[0].Dot(Cam, Cam_U_Right);
	T[1][0] = Cam_V_UP.x;		T[1][1] = Cam_V_UP.y;		T[1][2] = Cam_V_UP.z;			T[1][3] = -v3[0].Dot(Cam,Cam_V_UP);
	T[2][0] = Cam_N_Direction.x;T[2][1] = Cam_N_Direction.y;T[2][2] = Cam_N_Direction.z;	T[2][3] = -v3[0].Dot(Cam,Cam_N_Direction);
	T[3][0] = 0;				T[3][1] = 0;				T[3][2] = 0;					T[3][3] = 1;
	MultiplyMatrix3();
}
