#include <windows.h> /* 引入wingdi.h */
#include <stdio.h>

int main(){
	HWND mywin; /*控制台窗口句柄*/
	HDC  mydc; /* 控制台绘图DC */
	char title[256];/* 保存控制台标题 */
	RECT r; /*窗口矩形区域*/
	
	GetConsoleTitle(title,256);/* 获取控制台标题 */
	mywin=FindWindow(0,title);/* 获取控制台句柄 */
	mydc = GetDC(mywin); /* 获取控制台绘图DC */
	printf("Init ok\n");
	Ellipse(mydc,0,0,50,50);/*通过Ellipse函数画一个圆 */
	
	printf("Draw Ecclipse successfully\n");
	
	GetClientRect(mywin, &r); //获得控制台窗口举行区域
    if (r.bottom == 0) { //判断窗口区域是否有可显示区域
		printf("There is not viewable area in the windows.\n");
    }
	else {
		//随机绘制一万个红色的点
		for (int i=0; i<100000; i++) {
			int x = rand() % r.right;
			int y = rand() % r.bottom;
			SetPixel(mydc, x, y, RGB(255, 0, 0));
		}
	}
	
	getchar();
	return 0;
}