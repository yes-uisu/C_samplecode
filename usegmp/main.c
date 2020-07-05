/*
如何使用GMP库的最简单示例

Author：李晓峰
Date：2020.7.1
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/

#include <stdio.h>
#include <stdlib.h>
/*在一些编译环境中，如IDE中，需在linker settings 中加入需要链接的库"*.a"
gcc 命令行：gcc main.c -L./libs -lgmp
*/
#include "gmp.h"//还


int main()
{
    //下面的程序块是演示gmp的基本应用
    mpz_t t; //mpz_t 为GMP内置大数类型
	mpz_init(t); //大数t使用前要进行初始化，以便动态分配空间
	mpz_ui_pow_ui(t,2,100); //GMP所有函数基本都是以mpz打头
	gmp_printf("2^100=%Zd\n",t); //输出大数，大数的格式化标志为%Zd
	mpz_clear(t);//清除大数占用的内存
}
