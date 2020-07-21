/*
Noter：李晓峰
Date：2020.7.21
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
Description:
这个例子展示如何在一个窗体中显示一个bmp文件。
*/

#ifndef UNICODE
	#define UNICODE
#endif 

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc; //将消息处理回调函数地址保存在这个结构体中
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Show BMP file in window",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

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

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

/*消息处理的回调函数
Noter：李晓峰
Date：2020.7.21
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HBITMAP g_hbmBall = NULL; 
	BITMAP bm;
	HDC hdc;
	
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT://绘制bmp图片
        {
			//加载bitmap图片
			g_hbmBall = (HBITMAP)LoadImage(NULL, TEXT("buusecurity.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
						
			//获取加载的图片信息
			GetObject(g_hbmBall, sizeof(bm), &bm);
						
			/*The CreateCompatibleDC function creates a memory device context (DC) 
			  compatible with the specified device.
			*/
			HDC hdcMem = CreateCompatibleDC(NULL);
			
			/*
			The SelectObject function selects an object into the specified device context (DC). The new object replaces the previous object of the same type.
			Object includes bitmap, brush, font,pen,region.
			*/
			HBITMAP hbmOld = SelectObject(hdcMem, g_hbmBall);
			
			hdc=GetDC(hwnd);
			/*
			The BitBlt function performs a bit-block transfer of the color data corresponding to a rectangle of pixels from the specified source device context into a destination device context.
			*/
			BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
			
			SelectObject(hdcMem, hbmOld);
			DeleteDC(hdcMem);
			
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}