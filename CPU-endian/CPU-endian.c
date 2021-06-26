/*
Author；Lixiaofeng
Date：2021.6.16
web：http://buuer_xxtxiaofeng.gitee.io/lxf/

目的：
    此示例程序展示如何判断CPU存储数据的方式是Big-endian，还是Little-endian。
	Big-endian：先存高位，也就是高位在低地址单元。
	Big-endian：先存低位，也就是高位在高地址单元。
编译：
   使用gcc进行编译，编译指令：gcc -g -o cpu-endian.exe CPU-endian.c
备注：
    1、执行cpu-endian.exe可以看到检测结果。
	2、可以通过gdb单步执行，看看存储顺序。
	   a) 加载文件：gdb cpu-endian.exe
	      或者执行gdb，进入gdb命令行状态，执行：file cpu-endian.exe
	   b) 查看源代码：l 
	   c) 在变量赋值语句后设置断点：b 25
	   d) 运行至断点处：r
	   e) 查看x的值:
	        十进制显示：p x
			十六进制显示：p/x x
	   f) 查看x地址：p &x
	   g) 显示x地址开始，存的两个byte值：x /2xb 0x61ff1c
	     我们可以从显示的数值上看到存储顺序。
说明：
        Bit order usually follows the same endianness as the byte order for a given computer system. That is, in a big endian system the most significant bit is stored at the lowest bit address; in a little endian system, the least significant bit is stored at the lowest bit address.
*/

#include <stdio.h>
int main()
{
    short int x;
    char x0,x1;
    x = 0x1122; /*二进制: 0001 0001 0010 0010*/
    x0 = ((char*)&x)[0]; //低地址单元
    x1 = ((char*)&x)[1]; //高地址单元
    if(x0 == 0x11)
        printf("Big-endian\n");
    else
		printf("Little-endian\n");
	return 0;
}  
