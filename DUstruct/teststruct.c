/*
Author；Lixiaofeng
Date：2020.6.23
web：http://buuer_xxtxiaofeng.gitee.io/lxf/

目的：
    此程序时《现代密码学》关于协议数据结构定义的示例程序，对于对结构体的使用不是很熟悉的同学，
特别需要注意的结构体后面变长数据的处理。

编译：
    此程序在windows环境下，用gcc编译通过
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义一个协议的版本号，这样程序在通信时可以判断此版本号是否在其可处理范围内
//也可以根据不同版本后的协议，选择不同的处理程序。
#define MsgVersion 1

//使用枚举类型定义协议中的各种消息类型，可读性好
enum MsgType{
	SENDPAR=1, //发送共享参数
	PAROK, //确认收到共享参数
	MyNum, //发送计算后的参数
	Bye //共享密钥交换完成
};

//定义协议的数据结构	
typedef struct _DH_PROTOCOL
{
	unsigned char version; //版本 
	enum MsgType type;   //消息类型
	unsigned short p; //参数p
	unsigned short a; //参数a
	unsigned short YAB; //共享给对方的数值
	//unsigned int datasize; //此例子时一个字符串，字符串有结束符，可以不要这个定义
	char data[];
}DH_Protocol;

int main()
{
	/*test 1 block
	定义结构体变量，并进行赋值和访问
	*/
	DH_Protocol a;
	a.version=MsgVersion;
	a.type=SENDPAR;
	printf("hello\n");
    printf("version:%i,type:%i \n",a.version,a.type);
	
	/*test2 block
	定义结构体指针，示例带数据的变长结构体的基本使用方法
	*/
	char * textdata="abc";
	DH_Protocol * aa = NULL;
	printf("message header size is %i.\n",sizeof(DH_Protocol));
	printf("string size is %i.\n",strlen(textdata));
	
	//注意在下面的分配空间计算时需要加1，因为你要把字符串的结束符'\0'计算在内
	//如果你时二进制的数据，就不需要了，但是你就要在你的结构体里面记录二进制数据的长度
	aa=malloc(sizeof(DH_Protocol)+strlen(textdata)+1);
	
	if(aa == NULL){
		printf("malloc failed.\n");
	}
	else{
		printf("not NULL.\n");
		aa->version=MsgVersion;
		printf("version:%i,",aa->version);
		aa->type=MyNum;
		printf("type:%i ",aa->type);
		strcpy(aa->data,textdata);
		printf("data:%s\n",aa->data);
		free(aa);
	}
		
    return 0;
}
