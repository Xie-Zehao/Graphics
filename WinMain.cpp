#ifndef UNICODE
#define UNICODE
#endif 
#include "Vector3.h"

#include "Matrix.h"
#include "MatrixV3_Model.h"
#include "MatrixV3_View.h"
#include "MatrixV3_Projection.h"
#include "MatrixV3_ViewPort.h"

#include"Triangle.h"
#include "Tool.h"
#include "Cube.h"
#include "Face.h"
#include <windows.h>
//#include "Line.h"

#define WM_KEYDOWN                      0x0100
#define WM_PAINT                        0x000F

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Re gister the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";
    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClass(&wc);
    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"MiniXie_Student's Graphics",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style
        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 700  , 700,
        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );
    if (hwnd == NULL)
    {
        return 0;
    }
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    // Run the message loop.
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        //��������л�ͼ
        //HDC hdc = GetDC(hwnd);//��ȡ���ھ��
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc; //be used to get Device Context
    HDC hcdc;// be used to get Device Compatible Context, saved in memory.
    HPEN hp;// create paint pen
    HBITMAP BM;// create variable Bitmap;
    //����ִ�д���
    Line l1;
    float x=0, y=0, z=0;
    float Dx=0, Dy=0, Dz=0;
    float alpha=0, beta=0, gamma=0;
    MatrixV3_Model M = MatrixV3_Model(x,y,z,alpha,beta,gamma,Dx,Dy,Dz);//����M����
    MatrixV3_View V = MatrixV3_View(0, 0, 0, 0, 0, -1, 0, 1, 0);//����V����������꣨1��1��1��������2��2��2��
    //l = -1, r = 1, b = -1, t = 1, n = 0.1, f = 100
    MatrixV3_Projection P = MatrixV3_Projection(120, 1, 0.1, 100);//����P����
    MatrixV3_ViewPort ViewPort = MatrixV3_ViewPort(700,700);//�����ӿھ���
    Matrix V_M = V * M;//������ձ任����M 
    Matrix P_V_M = P * V_M;//������ձ任����M 
    Matrix V_P_V_M = ViewPort * P_V_M;
    

    //����һ�������ε�������
    Vector3 v[3];
    v[0] = Vector3(2, 0, -2);
    v[1] = Vector3(0, 2, -2);       
    v[2] = Vector3(-2, 0, -2);  

    //�����κ;�����а�
    M.v3 = v;
    M.v3number = 3;
    //��������������������ν��а�
    Triangle tri(M.v3);

    //MultiplyMatrix ���Եõ�����ĵ�ַ����Ҫ�������¸�ֵ
    Vector3 Result[3];
    Result[0] = MultiplyMatrix(V_P_V_M.T, M.v3, M.v3number)[0];
    Result[1] = MultiplyMatrix(V_P_V_M.T, M.v3, M.v3number)[1];
    Result[2] = MultiplyMatrix(V_P_V_M.T, M.v3, M.v3number)[2];
    //���Ѿ��任�������������������
    tri.setRP(Result);

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        hdc = BeginPaint(hwnd, &ps); //Destination DC
        hcdc = CreateCompatibleDC(hdc);//create Source DC in Memory
        BM = CreateCompatibleBitmap(hcdc, 0, 0);//create bitmap through Source DC
        SelectObject(hcdc, BM);// select bitmap into DC
        BitBlt(hdc, 0, 0, 700, 700, hcdc, 0, 0, SRCCOPY);//Copy hcdc to hdc
        //now,we have created a var HDC and a var HCDC ,we just need to draw it in HCDC 
        hp = CreatePen(1, 3, RGB(0, 0, 0));//create pen
        SelectObject(hcdc, hp);// select pen into DC

        MoveToEx(hdc, Result[0].x, Result[0].y, NULL);
        LineTo(hdc, Result[1].x, Result[1].y);
        LineTo(hdc, Result[2].x, Result[2].y);
        LineTo(hdc, Result[0].x, Result[0].y);

        ReleaseDC(hwnd, hdc);//�ͷŴ��ھ��
        DeleteObject(hp);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps);
    }break;
    case WM_KEYDOWN:
    {
        if (wParam == VK_UP) {
            y--;
        }
        if (wParam == VK_DOWN) {
            y++;
        }
        if (wParam == VK_RIGHT) {
            x = x + 2;
        }
        if (wParam == VK_LEFT) {
            x=x-2;
        }
        //PostQuitMessage(0);//����ֱ���˳���˵���������Ч��
        InvalidateRect(hwnd, NULL, true);  
    }break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}