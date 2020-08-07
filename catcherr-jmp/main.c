/*
源程序来源于 https://www.jianshu.com/p/f98d5b314a10
*/

/*
实现C语言中类似于C++中的try/catch错误捕获
*/

#include <stdio.h>
#include <setjmp.h>

#define try if ((jmp_ret = setjmp(env)) == 0)
#define catchany else if (1)
#define catch(v) else if (jmp_ret == v)

#define ERROR_VALUE1 -1
#define ERROR_VALUE2 -2
#define OK_VALUE 1
static jmp_buf env;
static int jmp_ret;
struct table{
    int value;
    char *name;
};

//4个测试值
static struct table table[4] = {
    {OK_VALUE, "OK_VALUE"},
    {ERROR_VALUE1, "ERROR_VALUE1"},
    {ERROR_VALUE2, "ERROR_VALUE2"},
    {-100, NULL}
};

//被测试的函数，这个函数只有传入OK_VALUE才认为正常，其它情况异常
void test(int value){
    if (value != OK_VALUE){
        longjmp(env, value);
    }
}

int main(int argc, char **argv)
{
    int i;
    //轮流测试4个值
    for (i = 0; i < 4; ++i){
        try{
            test(table[i].value);
            printf("use %s test pass!\n", table[i].name);
        }
        catch(ERROR_VALUE1){
            printf("test fail with error=%s!\n", table[i].name);
        }
        catch(ERROR_VALUE2){
            printf("test fail with error=%s!\n", table[i].name);
        }
        catchany{
            printf("test fail with error=%d!\n", jmp_ret);
        }
    }

    return 0;
}
