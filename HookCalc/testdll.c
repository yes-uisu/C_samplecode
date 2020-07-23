/*
这是个动态链接库，实现了准备注入的钩子函数。
copy from：https://blog.csdn.net/weixin_34342207/article/details/88721250
2020.7.22
*/
#include <windows.h>
#include <tchar.h>

BOOL test()
{
    MessageBox(NULL, TEXT("I am Hook function!"), TEXT("Tips"), MB_OK);
    return 0;
}

/*
动态链接库要按照windows定义的框架去编写。
*/
BOOL WINAPI DllMain(HINSTANCE hinstDll, DWORD dwReason, LPVOID lpvRevered)
{
    // MessageBox(NULL, TEXT("This is DllMain!"), TEXT("Tips"), MB_OK);
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        /* 只有第一次会进到这里，之后再次Attach不会产生DLL_PROCESS_ATTACH，只会增加DLL的调用次数 */
        MessageBox(NULL, TEXT("Process Load Dll Success!"), TEXT("Tips"), MB_OK);
        break;
    case DLL_PROCESS_DETACH:
        // MessageBox(NULL, TEXT("Process Unload Dll Success!"), TEXT("Tips"), MB_OK);
        break;
    case DLL_THREAD_ATTACH:
        // MessageBox(NULL, TEXT("Thread load Dll Success!"), TEXT("Tips"), MB_OK);
        break;
    case DLL_THREAD_DETACH:
        // MessageBox(NULL, TEXT("Thread Unload Dll Success!"), TEXT("Tips"), MB_OK);
        break;
    }
    return TRUE;

}