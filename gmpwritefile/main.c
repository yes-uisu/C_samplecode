/*

��ʾ��������Ҫ��ʾ�������ļ���д��
����д��ʾ������ĳ�ʼ������ѧ����������ѧ�����ϰʱ���ô������������ֱ�Ӱ�������д���ļ���
�ᷢ���ļ����ȱ�ĺܳ�����Ϊ������ǽṹ�壩��ͨ�����漸������飬�����ô���˽�������м�����д
�����еĲ�����˼��Ȼ�����ո�������Ľ���취��
ע�⣺���ս����д���ļ�����Ҫ���Զ����Ʒ�ʽ�鿴�ļ������ݣ����д������ݡ�
Author��������
Date��2020.5.21
web��http://buuer_xxtxiaofeng.gitee.io/lxf/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gmp.h"


int main()
{
	FILE *fp;
	
	//���ṹ��д���ļ�
    //����ĳ��������ʾgmp�Ļ���Ӧ��
    mpz_t t,t1,t2,t3; //mpz_t ΪGMP���ô�������
	mpz_init(t); //����tʹ��ǰҪ���г�ʼ�����Ա㶯̬����ռ�
	mpz_set_ui(t,2); //GMP���к�������������mpz��ͷ
	gmp_printf("t=%Zd\n",t); //��������������ĸ�ʽ����־Ϊ%Zd
	fp=fopen("data","wb");
	mpz_out_raw(fp,t);
	fclose(fp);
	mpz_clear(t);
	
	/*------------------
	  ���Է���̶�λ��
	  -----------------*/
	mpz_init2(t1,512);
	mpz_set_ui(t1,2);
	gmp_printf("t1=%Zd\n",t1); //��������������ĸ�ʽ����־Ϊ%Zd
	fp=fopen("data1","wb");
	mpz_out_raw(fp,t1);
	fclose(fp);
	mpz_clear(t1);
	
	/*----------------------
	   ֻд��ֵ
	   ---------------------*/
	char *rawdata;
	long int memcount,numb;
	mpz_init(t2);
	mpz_set_ui(t2,2);
	gmp_printf("t2=%Zd\n",t2); //��������������ĸ�ʽ����־Ϊ%Zd
	numb=8*1-0;
	memcount=(mpz_sizeinbase(t2,2)+numb-1)/numb;
	rawdata=malloc(memcount);
	mpz_export(rawdata,NULL,1,1,1,0,t2);
	fp=fopen("data2","wb");
	fwrite(rawdata,1,memcount,fp);
	fclose(fp);
	mpz_clear(t2);
	free(rawdata);
	
	/*-------------------------
	   ����̶���С�ռ�д����ֵ t3
	----------------------------*/
	long int offset;
	mpz_init(t3);
	//mpz_set_ui(t3,2);
	//mpz_set_ui(t3,4096); //write 0x1000
	mpz_set_ui(t3,4095); //write 0xFFF
	
	gmp_printf("t3=%Zd\n",t3); //��������������ĸ�ʽ����־Ϊ%Zd
	
	//����512bit=64bytes�Ŀռ�
	memcount=64;
	rawdata=malloc(memcount);
	//�ڴ��ʼ��������ȥ���󿴿����
	if(rawdata!=NULL)
		memset(rawdata,0,64);
	
	//������ڵ�ƫ��
	numb=8*1-0;
	offset=64-(mpz_sizeinbase(t3,2)+numb-1)/numb;
	//��������
	mpz_export(rawdata+offset,NULL,1,1,1,0,t3);
	fp=fopen("data3","wb");
	fwrite(rawdata,1,memcount,fp);
	fclose(fp);
	free(rawdata);
	
	//read from file
	rawdata=malloc(memcount);
	//�ڴ��ʼ��������ȥ���󿴿����
	if(rawdata!=NULL)
		memset(rawdata,0,64);
	
	//check t3 
	mpz_set_ui(t3,0);
	gmp_printf("t3=%Zd\n",t3);
	
	fp=fopen("data3","rb");
	fread(rawdata,1,memcount,fp);
	mpz_import(t3,64,1,1,1,0,rawdata);
	fclose(fp);
	
	//check t3 read from file
	gmp_printf("t3=%Zd\n",t3);
	
	free(rawdata);
	
	mpz_clear(t3);
}
