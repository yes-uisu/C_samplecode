/*
如何利用windows操作系统自带的机制，向windows自带的计算器，注入钩子函数。
copy from：https://blog.csdn.net/weixin_34342207/article/details/88721250
(
我们可以使用特定的线程ID来安装线程消息钩子，核心就是要获取线程的ID
我主要是用CreateToolhelp32Snapshot创建进程快照然后配合TH32CS_SNAPPROCESS TH32CS_SNAPTHREAD这两个结构体获取线程ID！当然还可以用GetWindowsThreadProcessId
配合窗口句柄快速获取进程ID然后得到线程ID
)
注意：
首先要把calc.exe运行起来，才能挂钩子函数。
2020.7.22
*/

#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>

int getThreadID(int pid)

{
    THREADENTRY32 te32;
    te32.dwSize = sizeof(te32);
    HANDLE Snapshot_thread = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (Snapshot_thread != INVALID_HANDLE_VALUE)
    {
        if (Thread32First(Snapshot_thread, &te32))
        {
            do
            {
                if (te32.th32OwnerProcessID == pid)
                {
                    return te32.th32ThreadID;
                }
            } while (Thread32Next(Snapshot_thread, &te32));
        }
    }
    CloseHandle(Snapshot_thread);
    return 0;
}

 

int getPID(char *target)
{
    PROCESSENTRY32 pe32;
    MODULEENTRY32 me32;
    HANDLE hProcess, hSnapshot_proc, hSnapshot_mod;
    pe32.dwSize = sizeof(pe32);
    hSnapshot_proc = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (Process32First(hSnapshot_proc, &pe32))
    {
        do
        {
            if (!strcmp(pe32.szExeFile, target))
            {
                return pe32.th32ProcessID;
            }
        } while (Process32Next(hSnapshot_proc, &pe32));
    }
    CloseHandle(hSnapshot_proc);
    return 0;
}

 

int main(int argc, char *argv)
{
    int i;
    HMODULE hdll = LoadLibrary("testdll.dll");
    HOOKPROC hproc = (HOOKPROC)GetProcAddress(hdll, TEXT("test"));
	
	/*
	win10中的计算器为caculator.exe,而不是原示例中的calc.exe
	*/
    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD, hproc, hdll, getThreadID(getPID("calc.exe")));

    for (i = 0; i < 10; i++)
    {
        Sleep(1000);
		Beep(2620,200);
    }
    UnhookWindowsHookEx(hook);
    return 0;
}