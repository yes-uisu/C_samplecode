/*
Noter：李晓峰
Date：2020.7.21
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
这个例子展示如何利用windows 的API创建一个带menu的窗体.
同时使用resource.h定义了资源文件中的常量。
同时对菜单事件进行响应。
*/

#ifndef UNICODE
	#define UNICODE
#endif 

#include <windows.h>
#include "resource.h" //程序中需要使用资源编号

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
Date：2020.7.9
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HMENU hMenu;
	int wmId;
		
    switch (uMsg)
    {
	case WM_CREATE:
		//此消息是在窗体创建时击发
		//在窗体创建时，动态加载菜单，并关联到窗体
		hMenu = LoadMenu(NULL,TEXT("WIN_MENU"));
		SetMenu(hwnd,hMenu);
		return 0;
	case WM_COMMAND:
		//响应菜单事件
		switch(LOWORD(wParam)) {
			case IDM_ELLIPSE:
				MessageBox(NULL,(LPCWSTR)L"Click ELLIPSE Menu ",
					(LPCWSTR)L"Alert",MB_OK | MB_ICONINFORMATION);
				break;
			case IDM_RECTANGLE:
				MessageBox(NULL,(LPCWSTR)L"Click RECTANGLE Menu ",
						(LPCWSTR)L"Alert",MB_OK | MB_ICONINFORMATION);
				break;
			case IDM_ROUNDRECT:
				MessageBox(NULL,(LPCWSTR)L"Click ROUNDRECT Menu ",
						(LPCWSTR)L"Alert",MB_OK | MB_ICONINFORMATION);
				break;
		}
		break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}