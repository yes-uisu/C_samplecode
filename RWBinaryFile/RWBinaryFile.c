/*
Description：
如何以二进制方式打开文件，对文件进行基本读写。
程序执行过程为：
1中存储了字母一个自己数据，此数据为0x00，程序读出此字节，然后+1，变成0x01，写入2
当执行此程序时，可以把2文件先删除，执行成功后会创建2
用一个可以用二进制方式查看文件内容的编辑器和查看器，查看1、2中的内容.
文件内容的二进制查看工具有UltraEdit，Notepad++（需要安装HexEditor插件）

compile:
gcc -o RWBinaryfile.exe RWBinaryfile.c

Author：李晓峰
Date：2021.4.6
web：http://buuer_xxtxiaofeng.gitee.io/lxf/
*/

#include <stdio.h>
 
int main()
{
   FILE *binaryfp = NULL;
   char buff;
   size_t PutCRet;
 
   binaryfp = fopen("1", "rb");//以二进制读方式打开文件
   if(binaryfp != NULL){
		/* 将文件的读取指针设为文件开始字节 */
		fseek(binaryfp, 0, SEEK_SET);
		
		fread(&buff,1,1,binaryfp);
		printf("get '%1x' form 1.\n", buff );
		buff=buff+1;
		fclose(binaryfp);
		
		/*以写方式打开文件，如果文件不存在，会创建，
		如果文件存在则会清空文件内容*/
		binaryfp = fopen("2", "wb");
		if(binaryfp != NULL){
			PutCRet=fwrite(&buff,1,1,binaryfp);
			if(PutCRet != 1)
				printf("Write '%1x' to 2 failed.\n",buff);
			else
				printf("Write '%1x' to 2 successfully.\n",buff);
			fclose(binaryfp);
		}
		else
			printf("Open 2 file failed！\n");	
   }
   else
	   printf("Open 1 file failed！\n");
}