/*
示例在源代码层次的分模块设计的方法

Author：李晓峰
Date：2020.7.1
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/
#include <stdio.h>
#include <stdlib.h>

#include "mymath.h"

int main()
{
    //下面是演示如果调用自定义的库函数
	printf("%d * %d = %d",2,3,myfun(2,3));
}
