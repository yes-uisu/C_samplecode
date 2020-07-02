/*

此示例程序主要演示大数的文件读写。
引发写此示例程序的初始问题是学生在做密码学编程练习时，用大数库计算后，如果直接把运算结果写入文件，
会发现文件长度变的很长（因为存入的是结构体），通过下面几个程序块，首先让大家了解大数库中几个读写
函数中的参数意思，然后最终给出问题的解决办法。
注意：最终结果会写入文件，需要用以二进制方式查看文件的内容，理解写入的内容。
Author：李晓峰
Date：2020.5.21
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gmp.h"


int main()
{
	FILE *fp;
	
	//将结构体写入文件
    //下面的程序块是演示gmp的基本应用
    mpz_t t,t1,t2,t3; //mpz_t 为GMP内置大数类型
	mpz_init(t); //大数t使用前要进行初始化，以便动态分配空间
	mpz_set_ui(t,2); //GMP所有函数基本都是以mpz打头
	gmp_printf("t=%Zd\n",t); //输出大数，大数的格式化标志为%Zd
	fp=fopen("data","wb");
	mpz_out_raw(fp,t);
	fclose(fp);
	mpz_clear(t);
	
	/*------------------
	  尝试分配固定位数
	  -----------------*/
	mpz_init2(t1,512);
	mpz_set_ui(t1,2);
	gmp_printf("t1=%Zd\n",t1); //输出大数，大数的格式化标志为%Zd
	fp=fopen("data1","wb");
	mpz_out_raw(fp,t1);
	fclose(fp);
	mpz_clear(t1);
	
	/*----------------------
	   只写数值
	   ---------------------*/
	char *rawdata;
	long int memcount,numb;
	mpz_init(t2);
	mpz_set_ui(t2,2);
	gmp_printf("t2=%Zd\n",t2); //输出大数，大数的格式化标志为%Zd
	numb=8*1-0;
	memcount=(mpz_sizeinbase(t2,2)+numb-1)/numb;
	rawdata=malloc(memcount);
	mpz_export(rawdata,NULL,1,1,1,0,t2);
	fp=fopen("data2","wb");
	fwrite(rawdata,1,memcount,fp);
	fclose(fp);
	mpz_clear(t2);
	free(rawdata);
	
	/*-------------------------
	   分配固定大小空间写入数值 t3
	----------------------------*/
	long int offset;
	mpz_init(t3);
	//mpz_set_ui(t3,2);
	//mpz_set_ui(t3,4096); //write 0x1000
	mpz_set_ui(t3,4095); //write 0xFFF
	
	gmp_printf("t3=%Zd\n",t3); //输出大数，大数的格式化标志为%Zd
	
	//分配512bit=64bytes的空间
	memcount=64;
	rawdata=malloc(memcount);
	//内存初始化，可以去掉后看看结果
	if(rawdata!=NULL)
		memset(rawdata,0,64);
	
	//计算存在的偏移
	numb=8*1-0;
	offset=64-(mpz_sizeinbase(t3,2)+numb-1)/numb;
	//保存数据
	mpz_export(rawdata+offset,NULL,1,1,1,0,t3);
	fp=fopen("data3","wb");
	fwrite(rawdata,1,memcount,fp);
	fclose(fp);
	free(rawdata);
	
	//read from file
	rawdata=malloc(memcount);
	//内存初始化，可以去掉后看看结果
	if(rawdata!=NULL)
		memset(rawdata,0,64);
	
	//check t3 
	mpz_set_ui(t3,0);
	gmp_printf("t3=%Zd\n",t3);
	
	fp=fopen("data3","rb");
	fread(rawdata,1,memcount,fp);
	mpz_import(t3,64,1,1,1,0,rawdata);
	fclose(fp);
	
	//check t3 read from file
	gmp_printf("t3=%Zd\n",t3);
	
	free(rawdata);
	
	mpz_clear(t3);
}
