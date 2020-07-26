/*
Author:Li Xiaofeng
Date:2020.7.26
Description:
这是使用windows API EnumFontFamilies来枚举操作系统内安装的所有字体，
这里有一个回调函数EnumFamCallBack，当系统每次找到一个字体时，回调
此函数。
此示例将找到的字体名字在终端打印出来
*/

#ifndef UNICODE
	#define UNICODE
#endif 



#include <windows.h>
#include <wingdi.h>
#include <winuser.h>
#include <stdio.h>
#include <stdlib.h>

//枚举字体时的回调函数声明
BOOL CALLBACK EnumFamCallBack(LPLOGFONT lplf, LPNEWTEXTMETRIC lpntm, DWORD FontType, LPVOID aFontCount);


int main(){
	HWND mywin; /*控制台窗口句柄*/
	HDC  mydc; /* 控制台绘图DC */
	char title[256];/* 保存控制台标题 */
	
	
	GetConsoleTitle(title,256);/* 获取控制台标题 */
	mywin=FindWindow(0,title);/* 获取控制台句柄 */
	mydc = GetDC(mywin); /* 获取控制台绘图DC */
	
    EnumFontFamilies(mydc, (LPCTSTR) NULL, 
		(FONTENUMPROC) EnumFamCallBack, (LPARAM) NULL); 
									
    return 0;

}

//枚举字体时的回调函数具体实现
BOOL CALLBACK EnumFamCallBack(LPLOGFONT lplf, LPNEWTEXTMETRIC lpntm, DWORD FontType, LPVOID aFontCount) 
{ 
	//需要打印汉字，这是宽字符，所以使用wprintf
    wprintf(L"%ls \n",lplf->lfFaceName); 
} 

