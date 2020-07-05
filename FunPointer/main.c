/*
Author；Lixiaofeng
Date：2020.7.5

目的：
    此示例程序是展示函数指针的基本用法。
	在一些需要根据条件，动态决定数据处理方式的情况下，
	会与结构体结合使用，此示例也给出简单的展示。
	在linux内核模块中，这类程序设计比较普遍。
	比如iptalbes中对于包的处理方式，可以查看我以前写的一个文章：	李晓峰,张玉清,等.Linux2.4内核防火墙底层结构分析[J].计算机工程与应用,2002(14):138-140,144. 

*/

# include <stdio.h>

//函数声明
int Add(int,int);  
int Sub(int,int);

//定义一个结构体，结构体包含一个函数指针
typedef struct {
	int a;
	int b;
	int(*p)(int, int);//定义一个函数指针
}processunit;

int main(void)
{
    //根据
    processunit t;
	t.a=3;
	t.b=2;
	t.p=Add;
	printf("3+2=%d \n",(t.p)(t.a,t.b));
	t.p=Sub;
	printf("3-2=%d \n",(t.p)(t.a,t.b));
    
    return 0;
}

//Add函数的具体实现
int Add(int x, int y)  
{
    return x+y;
}

//Sub函数的具体实现
int Sub(int x, int y)  
{
    return x-y;
}