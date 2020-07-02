/*
此示例程序主要演示如何使用c语言的基本位操作实现一个LFSR(循环移位寄存器)。
寄存器长度为4个字节，也就是32bit，类型static unsigned long决定的
采用特定值00000000000000000000000000000011
b1^b2反馈至高位，所以就是0反馈至高位
移位后为00000000000000000000000000000001
反馈就不变

Author：李晓峰
Date：2020.7.2
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/

#include <stdio.h>

int main()
{
	static unsigned long a;
	a=0x3;
	printf("size:%i,Decimal:%i,Hexadecimal:%x\n",sizeof(a),a,a);
	
	//计算移位后的输出
	if(a & 0x00000001)
		printf("output bit is : 1\n");
	else
		printf("output bit is : 0\n");
	
	/*计算反馈位
	(a >> 1) ^ a 计算b1^b2 (先不考虑高位)
	& 0x00000001 屏蔽掉高位，剩下就是b1^b2
	<<31 将b1^b2移到最高位
	a >>1 右移移位
	用|置最高位
	*/
	printf("b2:%x\n",(a >> 1) & 0x00000001);
	printf("b1:%x\n",a & 0x00000001);
	printf("b2^b1:%x\n",((a >> 1) ^ a) & 0x00000001);
	printf("move to highest bit: %x\n",(((a >> 1) ^ a) & 0x00000001) << 31);
	a=((((a >> 1) ^ a) & 0x00000001) << 31) | (a >>1);
	printf("Decimal:%i,Hexadecimal:%x\n",a,a);
}