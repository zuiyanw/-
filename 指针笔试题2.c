#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //指针笔试题2
//由于还没学习结构体，这里告知结构体的大小是20个字节
struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
int main()
{
	//p=(struct Test*)0x100000   32个bit换16进制位为8个16进制位
	printf("%p\n", p + 0x1);
	// 0x1：16进制中的1  (p是一个结构体指针)p+1 跳过一个结构体 结构体20个字节 0x100000+20=0x100014 1为16 +4=20
	printf("%p\n", (unsigned long)p + 0x1);
	//unsigned long 强制转换为长整型-0x100000转换为：整数00100000 通过计算器算出-1048576 +1=1048577-100001
	printf("%p\n", (unsigned int*)p + 0x1);
	//把p强制转换为int*类型的指针 +1 跳过一个int的大小-int-4个字节 0x100004
	return 0;
}   //指针+-整数 取决于指针类型