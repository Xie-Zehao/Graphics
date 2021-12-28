#ifndef UNICODE
#define UNICODE
#endif 
#include "Vector3.h"

#include "Matrix.h"
#include "MatrixV3_Model.h"
#include "MatrixV3_View.h"
#include "MatrixV3_Projection.h"
#include "MatrixV3_ViewPort.h"

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
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style
        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 920, 1080,
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
        //到这里进行绘图
        //HDC hdc = GetDC(hwnd);//获取窗口句柄
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
    //这里执行代码
    int vnumber = 8;//定义顶点数量
    MatrixV3_Model M = MatrixV3_Model();//创建M矩阵
    MatrixV3_View V = MatrixV3_View(1, 1, 1, 2, 2, 2, 0, 1, 0);//创建V矩阵，相机坐标（1，1，1），看向（2，2，2）
    MatrixV3_Projection P = MatrixV3_Projection(2, 1, -1, -2, -1, -2);//创建P矩阵
    MatrixV3_ViewPort ViewPort = MatrixV3_ViewPort(1920,1080);//创建视口矩阵
    Matrix VP_P_V_M = ViewPort * (P * (V * M));//获得最终变换矩阵M 

    Vector3* v3 = new Vector3[vnumber]; //定义点数组
    v3[0] = Vector3(0, 0, 0);
    v3[1] = Vector3(100, 0, 0);
    v3[2] = Vector3(100, 100, 0);
    v3[3] = Vector3(0, 100, 0);
    v3[4] = Vector3(0, 0, 100);
    v3[5] = Vector3(100, 0, 100);
    v3[6] = Vector3(100, 100, 100);
    v3[7] = Vector3(0, 100, 100);
    M.v3 = v3; //将三维点和变换矩阵进行绑定
    M.v3number = 8;

    MultiplyMatrix(VP_P_V_M.T, M.v3,M.v3number );

    //其次创建正方体需要的六个面，用来记录面的顺序
    int fnumber = 6;
    Face* f = new Face[fnumber];
    f[0].index[0] = 4; f[0].index[1] = 5; f[0].index[2] = 6; f[0].index[3] = 7;//底层
    f[1].index[0] = 0; f[1].index[1] = 3; f[1].index[2] = 2; f[1].index[3] = 1;//顶层
    f[2].index[0] = 0; f[2].index[1] = 4; f[2].index[2] = 7; f[2].index[3] = 3;//前
    f[3].index[0] = 1; f[3].index[1] = 2; f[3].index[2] = 6; f[3].index[3] = 5;//右
    f[4].index[0] = 2; f[4].index[1] = 3; f[4].index[2] = 7; f[4].index[3] = 6;//后
    f[5].index[0] = 0; f[5].index[1] = 1; f[5].index[2] = 5; f[5].index[3] = 4;//左
    //将六个面和八个点和正方形进行连接
    Cube C1;
    C1.readFace(f);
    C1.readVector3(v3);
    //到这里我们的模型点坐标就创建好了，应该开始变换了
    M.Rotation(10, 10, 10);

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
        BitBlt(hdc, 0, 0, 920, 1080, hcdc, 0, 0, SRCCOPY);//Copy hcdc to hdc
        //now,we have created a var HDC and a var HCDC ,we just need to draw it in HCDC 
        hp = CreatePen(1, 3, RGB(0, 0, 0));//create pen
        SelectObject(hcdc, hp);// select pen into DC

        ReleaseDC(hwnd, hdc);//释放窗口句柄
        DeleteObject(hp);//

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps);
    }break;
    case WM_KEYDOWN:
    {
        if (wParam == VK_UP) {
        }
        if (wParam == VK_DOWN) {
        }
        if (wParam == VK_RIGHT) {
        }
        if (wParam == VK_LEFT) {
        }
        //PostQuitMessage(0);//可以直接退出，说明点击是有效的
        InvalidateRect(hwnd, NULL, true);  
    }break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}