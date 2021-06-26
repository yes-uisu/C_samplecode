/*
Description：
    命令行输出进度条。
示例代码参考：
    https://blog.csdn.net/wjwykw/article/details/55652568
    https://blog.csdn.net/qq_21475601/article/details/88746793


compile:
    gcc -o processbar.exe processbar.c

Author：李晓峰
Org: 北京联合大学智慧城市学院信息安全专业
Date：2021.6.26
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/

#include <stdio.h>
#include <unistd.h>

//定义ASCII字符：  ▏▎▍▊█ 
static const char *ponit[]={"\x20\x20", "\xA8\x87", "\xA8\x86", "\xA8\x84", "\xA8\x83", "\xA8\x80"};

/*
FunctionName:progress_bar
Description：
    显示条块进度条，进度条右边有百分比显示。
Parameter:
    int per :表示显示百分比，0~100
Return：
    无返回值
*/
void progress_bar(int per)
{
	int i=0;
	int num0=0;
 	printf("\r  ["); //此处\r 表示光标移动到本行开始处
 	num0  = (100-per)/5;
 	i = per;
	while(i>5)
	{
		printf("%s", ponit[5]);
		i -= 5;
	}
 	if(i)
	{
		printf("%s", ponit[i]);
	}
 	for(i=0;i<num0;i++)
	{
		printf("%s", ponit[0]);
	}
 	printf("] %2d%%", per);
 	if(per == 100)
	{
		printf("\n");//换行
	}
}

/*
FunctionName:progress_bar1
Description：
    显示#的进度条，进度条右边有循环-\|/显示和百分比显示。
Parameter:
    int per :表示显示百分比，0~100
Return：
    无返回值
*/
void process_bar1(int per)
{
	int i=0;
	char bar[102]={0};
	char *lab="-\\|/";
	if(per<=100)
	{
		while(i<=per)
		{
			bar[i++]='#';
			bar[i]='\0';
		}
	}
	printf("[%-101s][%d%%][%c]\r",bar,per,lab[per%4]);
	if(per == 100)
	{
		printf("\n");
	}
}

int main()
{
	int i=0;
	char bar[102]={0};
	char *lab="-\\|/";
	while(i<=100)
	{
		progress_bar(i);
		i++;
	}
	i=0;
	while(i<=100)
	{
		process_bar1(i);
		i++;
	}
	return 0;
}