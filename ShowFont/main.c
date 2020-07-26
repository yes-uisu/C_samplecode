/*
copy from https://docs.microsoft.com/en-us/windows/win32/learnwin32/your-first-windows-program
*/

#ifndef UNICODE
	#define UNICODE
#endif 

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"FontWin";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc; //将消息处理回调函数地址保存在这个结构体中
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to use font",           // Window text
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
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        {
            HDC hdc = GetDC(hwnd);
            HFONT hFont, hOldFont; 

			// Retrieve a handle to the variable stock font.  
			hFont = (HFONT)GetStockObject(ANSI_VAR_FONT); 

			// Select the variable stock font into the specified device context. 
			if (hOldFont = (HFONT)SelectObject(hdc, hFont)) 
			{
				// Display the text string.  
				TextOut(hdc, 10, 50, L"Sample ANSI_VAR_FONT text", 25); 

				// Restore the original font.        
				SelectObject(hdc, hOldFont); 
			}
            
			
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}