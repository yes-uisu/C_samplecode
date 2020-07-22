/*
Noter：李晓峰
Date：2020.7.21
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
Description:
这个例子展示如何在终端显示图片。
程序在windows自带的cmd中显示正常，在其他第三方终端中也许不能显示图片。
*/

#include <windows.h>
#include <stdio.h>

 
int main(VOID) 
{ 
	HWND mywin; /*控制台窗口句柄*/
	HDC  mydc; /* 控制台绘图DC */
	char title[256];/* 保存控制台标题 */
	
    HBITMAP g_hbmBall = NULL; 
	BITMAP bm;
	
    GetConsoleTitle(title,256);/* 获取控制台标题 */
	mywin=FindWindow(0,title);/* 获取控制台句柄 */
	mydc = GetDC(mywin); /* 获取控制台绘图DC */
	
	//加载bitmap图片
	g_hbmBall = (HBITMAP)LoadImage(NULL, "buusecurity.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if(g_hbmBall == NULL){
		printf("Load Bitmap file failed!Error Number:%d\n",GetLastError());
		return 0;
	}
	
	//获取加载的图片信息
	GetObject(g_hbmBall, sizeof(bm), &bm);
	printf("bitmap width:%d,height:%d\n",bm.bmWidth, bm.bmHeight);
	
	/*The CreateCompatibleDC function creates a memory device context (DC) 
	  compatible with the specified device.
	*/
	HDC hdcMem = CreateCompatibleDC(NULL);
	
	/*
	The SelectObject function selects an object into the specified device context (DC). The new object replaces the previous object of the same type.
	Object includes bitmap, brush, font,pen,region.
	*/
    HBITMAP hbmOld = SelectObject(hdcMem, g_hbmBall);

	/*
	The BitBlt function performs a bit-block transfer of the color data corresponding to a rectangle of pixels from the specified source device context into a destination device context.
	*/
    BitBlt(mydc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
	
    SelectObject(hdcMem, hbmOld);
	DeleteDC(hdcMem);
	
	printf("Pause.Input any char to go.\n");
	getchar(); //先不退出程序，这样可以看到显示的图片
    		
    return 0; 
}

