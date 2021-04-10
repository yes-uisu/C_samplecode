/*
Description：
    示例Windows下编写终端程序，如何输出汉字。
	ASCII码编码模式是1一个字节。
	Unicode 根据要编码的数据类型使用两种编码格式：8 位和 16 位。
	在 UTF-8 中，ASCII 和控制字符 由通常的单字节代码表示，但其他字符变为双字节或更多字节。
	UTF 8 可以对非补充和补充字符进行编码。UTF-8 字符的最大长度可以为 4 个字节。非补充字符
	的最大长度为 3 个字节，而补充字符的长度为 4 个字节。
参考：
	https://www.ibm.com/docs/zh/db2/10.5?topic=support-unicode-character-encoding
	
compile: 
	gcc -o prtch.exe prtch.c

Author；李晓峰
Date：2021.4.9
web：http://buuer_xxtxiaofeng.gitee.io/lxf/

*/

# include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
    printf("--------printf-------------\n");
	printf("English.\n");  //可以正常显示
	
	printf("--------printf-------------\n");
	printf("中文 \n");  //中文不能正常显示
	
	printf("--------wprintf------------\n");
	wprintf(L"中文 \n");  //中文不可以正常显示
	
	printf("----------set local---------\n");
	setlocale(LC_CTYPE, "");  //设置本地化信息
	
	printf("--------printf-------------\n");
	printf("中文 \n");  //中文依然不能显示
	
	printf("--------wprintf------------\n");
	/*注意以下字符串前需要加L，加L是
	告诉编译器这是一个Unicode字符串*/
	wprintf(L"中文 \n");  //中文可以正常显示
    
    return 0;
}