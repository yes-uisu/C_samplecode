/*
请按照要求加入文件头
*/
#include <stdio.h>
#include <stdlib.h>

#include "mymath.h"

int main()
{
    //下面是演示如果调用自定义的库函数
	printf("%d * %d = %d",2,3,myfun(2,3));
}
