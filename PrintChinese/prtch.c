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
Date：2021.4.21
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
注意：
1.当你复制一个中文的字符串给你一个变量时，你赋予这个变量什么最终是什么
  与你源程序文件存储时的编码格式有关。

*/

# include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <winnls.h> //函数WideCharToMultiByte原型定义所在头文件

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
	
	wchar_t wstr[] = L"中文";       
    wprintf(L"%S\n",wstr); //小s为乱码
	
	//获得汉字字符数,输出:2
	printf("chinese character number: %d \n",wcslen(wstr));
	
	//获的wchar字符串所占字节数，因为遇0结束，所以后面连续两个0记为一个
	DWORD dwLen =WideCharToMultiByte( CP_ACP, 0, wstr, -1, 0, 0,0,0) ;
	printf("wchar string bytes: %d \n",dwLen);
	
	/*
	按字节打印出wstr十六进制内容,输出：2d 4e 87 65 0 0
	中的编码为4e 2d，存储方式为先2d ，后4e
	*/
	unsigned char *printpointer; //注意：此处如果不是unsigned char,而是char，printf时会有很多个f
	printpointer=(unsigned char *) wstr;
	for(int i=0;i<=dwLen;i++){
		printf("%#X   ",*printpointer);
		printpointer++;
	}
	printf("\n");
	
	/*“我”的UTF-8编码是 e6 88 91,Unicode编码 62 11*/
	unsigned char chinesestr[4];
	chinesestr[0]= 0x11;
	chinesestr[1]= 0x62;
	chinesestr[2]= 0x0;
	chinesestr[3]= 0x0;
	
	wprintf(L"%S\n",(wchar_t *)chinesestr);
	
	char buffer[20] = {};
    buffer[0] = 0xcc;
    buffer[1] = 0x96; /* “雌” 的 Unicode 码*/
    buffer[2] = 0xb4;
    buffer[3] = 0xdf; /*“催” 的 GB2312 码*/
    buffer[4] = '\0';
	wprintf(L"\n S format(Unicode): %S", buffer); /*Unicode显示正常*/
    wprintf(L"\n s format(GB2312): %s", buffer); /*GB2312显示正常*/

    return 0;
}