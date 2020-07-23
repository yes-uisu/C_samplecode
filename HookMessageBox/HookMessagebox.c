/*
采用函数注入的方式，实现钩子函数
originate from :https://bbs.csdn.net/topics/391821698?list=26502377
Noter；李晓峰
Date: 2020.7.23
Description:
再main函数中，可以看到有三个MessageBoxA，按照正常执行逻辑，分析显示：
	Before Hook!
	Hello world!
	After Hook!
但是在执行第二个MessageBoxA时，注入了钩子函数，将MessageBoxA替换为程序定义的函数
HookedMessageBoxA，在调用第二个MessageBoxA时，其实调用了HookedMessageBoxA，在此函数中
其调用MessageBoxA，显示：
	The message from hooked MessageBox!
*/
#include <windows.h>
#pragma comment(lib, "user32.lib")

#ifndef _X86_JMP_SIZE
	#define _X86_JMP_SIZE 6
#endif

void *g_pfnToHook = NULL;  //MessageBoxA的地址
void *g_pfnHooked = NULL;  //HookedMessageBoxA的地址

BYTE g_oldBytes[_X86_JMP_SIZE] = { 0 };
BYTE g_jmpBytes[_X86_JMP_SIZE] = { 0 };

DWORD g_dwProtect = 0;
DWORD g_dwResult = 0;

int WINAPI HookedMessageBoxA(
    HWND hWnd,
    LPCSTR lpText,
    LPCSTR lpCaption,
    UINT uType
)
{
    int iRet = -1;
	//Enables execute, read-only, or read/write access to the committed region of pages.
    if (VirtualProtect(g_pfnToHook, _X86_JMP_SIZE, PAGE_EXECUTE_READWRITE, &g_dwResult)) {
		//MessageBoxA的地址恢复回去，这样后面紧接着调用MessageBoxA可以正常
        memcpy(g_pfnToHook, (void *)g_oldBytes, _X86_JMP_SIZE);
		
        iRet = MessageBoxA(hWnd, "The message from hooked MessageBox!", lpCaption, uType);
		//将HookedMessageBoxA的地址覆盖到原来存储MessageBoxA的地址的内存
        memcpy(g_pfnToHook, (void *)g_jmpBytes, _X86_JMP_SIZE);
		//将对应的内存访问属性恢复回设置前状态
        VirtualProtect(g_pfnToHook, _X86_JMP_SIZE, g_dwProtect, &g_dwResult);
    }
    return iRet;
}

/*
Noter；李晓峰
Date: 2020.7.23
Description:
初始化钩子函数，
*/
BOOL InitializeMessageBoxHook(void)
{
	/*
	机器码0xE9是近跳转指令，其对应的汇编为JMP
	Opcode | Instruction
	--------------------
	E9 cw  |  JMP rel16
	--------------------
	E9 cd  |  JMP rel32
	--------------------
	*/
    BYTE jmpBytes[_X86_JMP_SIZE] = { 0xE9, 0x90, 0x90, 0x90, 0x90, 0xC3 };
    memcpy((void *)g_jmpBytes, (void *)jmpBytes, sizeof(jmpBytes));
	/*
	HookedMessageBoxA的地址-MessageBoxA的地址
	这个地址还要减去5，因为当前JMP指令是5个字节，跳转是从下一个指令开始计算
	*/
    DWORD jmpSize = (DWORD)((DWORD_PTR)g_pfnHooked - (DWORD_PTR)g_pfnToHook - 5);
	
	//Enables execute, read-only, or read/write access to the committed region of pages.
    BOOL fResult = VirtualProtect(g_pfnToHook, _X86_JMP_SIZE, PAGE_EXECUTE_READWRITE, &g_dwProtect);
    if (fResult) {
		/*
		将g_pfnToHook(也就是MessageBoxA的地址)拷贝到
		保护原地址空间中的内容到g_oldBytes数组中
		*/
		memcpy((void *)g_oldBytes, g_pfnToHook, _X86_JMP_SIZE);
		/*
		将计算的跳转相对数jmpSize，拷贝到JMP指令后面的区域
		*/
        memcpy((void *)&g_jmpBytes[1], (void *)&jmpSize, sizeof(jmpSize));
		/*
		将构造的JMP指令(机器指令)覆盖到存储MessageBoxA地址的空间上
		*/
        memcpy(g_pfnToHook, (void *)g_jmpBytes, _X86_JMP_SIZE);
		//将对应的内存访问属性恢复回设置前状态
        fResult = VirtualProtect(g_pfnToHook, _X86_JMP_SIZE, g_dwProtect, &g_dwResult);
    }
    return fResult;
}

BOOL FinalizeMessageBoxHook(void)
{
	//Enables execute, read-only, or read/write access to the committed region of pages.
    BOOL fResult = VirtualProtect(g_pfnToHook, _X86_JMP_SIZE, PAGE_EXECUTE_READWRITE, &g_dwResult);
    if (fResult) {
		//g_oldBytes数组中保存的MessageBoxA的地址恢复到原内存中
        memcpy(g_pfnToHook, g_oldBytes, _X86_JMP_SIZE);
    }
    return fResult;
}

int main(int argc, char *argv[])
{
	//获得MessageBoxA的地址
    g_pfnToHook = (void *)MessageBoxA;
	//获得HookedMessageBoxA的地址
    g_pfnHooked = (void *)HookedMessageBoxA;
	//这次调用的是系统MessageBoxA
    MessageBoxA(NULL, "Before Hook!", "before", MB_OK);

    if (InitializeMessageBoxHook()) {
		/*
		这次调用MessageBoxA，其实调用的是注入的函数
		所以会看到显示的文字不是Hello world
		*/
        MessageBoxA(NULL, "Hello world!", "info", MB_OK);
		//取消注入的钩子函数
        FinalizeMessageBoxHook();
    }
	//这次调用的是系统MessageBoxA
    MessageBoxA(NULL, "After Hook!", "after", MB_OK);

    return 0;
}