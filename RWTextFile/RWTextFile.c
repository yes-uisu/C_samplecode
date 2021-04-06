/*
Description：
如何以文本方式打开文件，对文件进行读写。
程序执行过程为：
1.txt中存储了字母a，程序读出此字符，然后+1，变成b，写入2.txt
当执行此程序时，可以把2.txt文件先删除，执行成功后会创建2.txt
用任务和文本编辑器，比如windows自带的notepad.exe查看2.txt中的内容

compile:
gcc -o RWTextfile.exe RWTextfile.c

Author：李晓峰
Date：2021.4.6
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/

#include <stdio.h>
 
int main()
{
   FILE *textfp = NULL;
   char buff;
   int PutCRet;
 
   textfp = fopen("1.txt", "r");//以读方式打开文件
   if(textfp != NULL){
		/* 将文件的读取指针设为文件开始字节 */
		fseek(textfp, 0, SEEK_SET);
		
		buff=fgetc(textfp);
		printf("get '%c' form 1.txt.\n", buff );
		buff=buff+1;
		fclose(textfp);
		
		/*以写方式打开文件，如果文件不存在，会创建，
		如果文件存在则会清空文件内容*/
		textfp = fopen("2.txt", "w");
		if(textfp != NULL){
			PutCRet=fputc((int)buff,textfp);
			if(PutCRet == EOF)
				printf("Write '%c' to 2.txt failed.\n",buff);
			else
				printf("Write '%c' to 2.txt successfully.\n",buff);
			fclose(textfp);
		}
		else
			printf("Open 2.txt file failed！\n");	
   }
   else
	   printf("Open 1.txt file failed！\n");
}