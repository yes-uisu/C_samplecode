/*
Noter:李晓峰
Date:2020.7.24

这是一个全局键盘钩子函数，也就是在操作系统进程上注入钩子函数。
originated from：https://blog.csdn.net/weixin_34342207/article/details/88721250
(做了些调整）
HHOOK WINAPI SetWindowsHookEx(
int idHook,
HOOKPROC lpfn,
HINSTANCE hMod,
DWORD dwThreadId);
=======================
idHook：钩子的类型，即它处理的消息类型
lpfn：指向dll中的函数或者指向当前进程中的一段代码
hMod：dll的句柄
dwThreadId：线程ID，当此参数为0时表示设置全局钩子
======================
备注：
网上示例是win xp 32位系统演示，所以没有编译位64位应用，但是由于win 10是64位的，所以在这里一定要编译位64应用。
*/



#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv)

{
    int i;

    HMODULE hdll = NULL;
    HOOKPROC hproc = NULL;
	HHOOK hook = NULL;
	
	hdll = LoadLibrary("testdll.dll");
	if(hdll == NULL){
		printf("LoadLibrary failed.\n");
		return 0;		
	}
	
	hproc = (HOOKPROC)GetProcAddress(hdll, "test");
	if(hproc == NULL){
		printf("Can't find test function.\n");
		return 0;		
	}
	
    hook = SetWindowsHookEx(WH_KEYBOARD, hproc, hdll, 0);
	if(hook == NULL){
		printf("Hook keyboard failed.\n");
		return 0;		
	}
	
    for(i=0;i<20;i++){
        Sleep(2000);
		Beep(2620,200);
    }

    UnhookWindowsHookEx(hook);

    return 0;

}