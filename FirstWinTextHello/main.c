/*
Noter：李晓峰
Date：2020.7.21
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
Description：
这个例子展示在窗体输出红色文本。
*/ 

#ifndef UNICODE
	#define UNICODE
#endif 

#include <windows.h>
#include <wingdi.h>  //TextOut 需要使用
//textout函数说明见：https://docs.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-textouta

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
        L"Learn to Program Windows",    // Window text
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
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
			COLORREF prevColor;
			
            HDC hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
			//set text color to red
			prevColor=SetTextColor(hdc,RGB(255,0,0));
			//再窗体输出字符串
			//此处需要TEXT宏，否则出现乱码
			TextOut(hdc, 0, 0,TEXT("Hello, Windows!"), 15); 
			//restore the text color
			SetTextColor(hdc,prevColor);
            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}