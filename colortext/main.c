/*
在命令行打出彩色文本。

Author：李晓峰
Date：2020.7.2
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/

#include <stdio.h>
#include <windows.h>   // WinApi header

int main()
{
	//这是指向输出终端的指针，在windows编程术语中称为句柄。
	HANDLE  hConsole;
	//此结构体是记录终端屏幕信息的，我们定义变量用来存储开始时设置，以便在测试结束后恢复
	CONSOLE_SCREEN_BUFFER_INFO remtextpar;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//获得当前终端的指针
	
	GetConsoleScreenBufferInfo(hConsole,&remtextpar);//获得当前终端屏幕参数
	
	/*
	函数原型定义
	BOOL WINAPI SetConsoleTextAttribute(_In_ HANDLE hConsoleOutput,_In_ WORD   wAttributes);
	第二个是终端属性，包括背景和前景等
	*/
	SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | FOREGROUND_RED);//设置文本颜色
	printf("%s\n", "I want to be nice today!");
	
	SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	printf("press <Enter>.\n");
	
	SetConsoleTextAttribute(hConsole, remtextpar.wAttributes);//恢复原设置
	
	getchar();  // wait
	return 0;
}