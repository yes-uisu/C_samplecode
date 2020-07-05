/*
Author；Lixiaofeng
Date：2020.7.5
web：http://buuer_xxtxiaofeng.gitee.io/lxf/

目的：
    此示例用两个有着相同函数的动态，来展示动态库的加载。
	示例虽然简单，但是大家可以体会，她是实现系统的
	可加载模块关键的方法。
*/


#include <dlfcn.h>//库的显示调用
#include <stdio.h>
#include <string.h>

/*自定义函数的声明，两个库里的函数原型都是一样的
大家可以体会一下，为什么我们在实现一些接口或者钩子函数时，
要求的函数原型必须保持特定的形式。
*/
#include "d.h" 

int main(int argc,char *argv[])
{
    
    void (*pStrLen)(void);// 函数指针
    void *pHandle = NULL;// 库指针
    char *pErr = NULL;// 错误指针
    
    /* 
	根据传递的参数，决定打开那一个动态链接库
	并检查是否打开成功。
	*/

	if(strcmp(argv[1],"1") == 0)
		pHandle = dlopen("./d1.so", RTLD_LAZY);
	else if(strcmp(argv[1],"2") == 0)
		pHandle = dlopen("./d2.so", RTLD_LAZY);
	else {
		printf("wrong parameters. Usage like: \n test 1 \n");
		return -1;
	}
	
	//获得错误信息
    pErr = dlerror();
    if(!pHandle || pErr != NULL){
		printf("Failed load library!\n%s\n", pErr);
		return -1;
	}
    
    // 获取testfun函数地址并检查是否有错误发生
    pStrLen = dlsym(pHandle, "testfun");
    pErr = dlerror();
    if(!pStrLen || pErr != NULL){
		printf("Error is %s\n", pErr);
		return -1;
	}
     
    // 调用testfun函数
	pStrLen();
    
     
    // 关闭库文件
    dlclose(pHandle);
    return 0;
}