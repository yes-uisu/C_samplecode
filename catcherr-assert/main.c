/************************************************************
 * 使用c语言的assert（断言）继续错误处理                    
 * 原型为：void assert(int expression);
 * assert函数是以宏的形式实现的。参数expression是一个在正常情况下应
 该为真的表达式。在执行assert函数时，会检测expression的值，如果结果
 为0（为假），则assert函数会向标准错误流输出断言失败的信息（包括断言
 函数的参数、调用断言函数的文件名和断言函数所在行号等信息），并调用
 abort函数终止程序 
 此程序及说明来源于：https://blog.csdn.net/lemonrabbit1987/article/details/48128693
 
 ************************************************************/

#include <stdio.h>
#include <assert.h>

int main()
{
  int x;
  printf("please input number:");
  scanf("%d", &x);
  /*
  如果输入大于0，则会由“符合要求”输出，否则，退出程序
  */
  assert(x > 0);

  printf("number is greater than 0!\n");

  return 0;
}