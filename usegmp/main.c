/*
�밴��Ҫ������ļ�ͷ
*/
#include <stdio.h>
#include <stdlib.h>
/*��һЩ���뻷���У���IDE�У�����linker settings �м�����Ҫ���ӵĿ�"*.a"
gcc �����У�gcc main.c -L./libs -lgmp
*/
#include "gmp.h"//��


int main()
{
    //����ĳ��������ʾgmp�Ļ���Ӧ��
    mpz_t t; //mpz_t ΪGMP���ô�������
	mpz_init(t); //����tʹ��ǰҪ���г�ʼ�����Ա㶯̬����ռ�
	mpz_ui_pow_ui(t,2,100); //GMP���к�������������mpz��ͷ
	gmp_printf("2^100=%Zd\n",t); //��������������ĸ�ʽ����־Ϊ%Zd
	mpz_clear(t);//�������ռ�õ��ڴ�
}
