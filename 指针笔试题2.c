#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //ָ�������2
//���ڻ�ûѧϰ�ṹ�壬�����֪�ṹ��Ĵ�С��20���ֽ�
struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
int main()
{
	//p=(struct Test*)0x100000   32��bit��16����λΪ8��16����λ
	printf("%p\n", p + 0x1);
	// 0x1��16�����е�1  (p��һ���ṹ��ָ��)p+1 ����һ���ṹ�� �ṹ��20���ֽ� 0x100000+20=0x100014 1Ϊ16 +4=20
	printf("%p\n", (unsigned long)p + 0x1);
	//unsigned long ǿ��ת��Ϊ������-0x100000ת��Ϊ������00100000 ͨ�����������-1048576 +1=1048577-100001
	printf("%p\n", (unsigned int*)p + 0x1);
	//��pǿ��ת��Ϊint*���͵�ָ�� +1 ����һ��int�Ĵ�С-int-4���ֽ� 0x100004
	return 0;
}   //ָ��+-���� ȡ����ָ������