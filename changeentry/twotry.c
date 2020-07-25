/*
示例如何修改程序的入口函数。正常编译程序入口函数是main，编译后执行
程序输出“Function is secentry,specific entry.”，编译时修改入口函数
为myentry，编译后，执行，程序输出"Function is main,default entry."
如何修改请看HowToCompile.txt文件。

Author：李晓峰
Date：2020.7.25
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/

# include <stdio.h>

// new entry point function 
int myentry();  
  

int main()
{
	printf("Function is main,default entry.\n");
	return 0;
}

int myentry()
{
	printf("Function is secentry,specific entry.\n");
	return 0;
}