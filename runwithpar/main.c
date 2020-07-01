#include <stdio.h>


int main(int argc,char *argv[])
{
	/*可执行程序文件名*/
	printf("%s\n",argv[0]);
	/*参数个数，需要注意的此计数包含可执行程序*/
	printf("parameter number:%i\n",argc);
	/*读取参数*/
	printf("parameter list(from 1):\n");
	int i = 1;
	while(i < argc)
	{
			printf("%s\n",argv[i]);
			i++;
	}
	//说明在dos和unix环境下,用""扩起来的表示其是一个字符串，代表着一个参数
	return 0;
}