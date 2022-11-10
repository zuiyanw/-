#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //指针笔试题1
int main()//指向函数指针数组 的指针
{ 
	
	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
		
	//程序的结果是什么？
	//a为首元素地址-&a+1-&b *(&b)=2    *(a + 1)=2
	//&a-整个a数组的地址 +1 跳过一个数组的地址 这是数组的地址为数组指针类型 int(*)[5] 强制类型转换int*  
	//ptr储存的跳过a[5]的地址 是一个int*类型 ptr-1向前移动4个字节 找到5的地址 解引用找到5
	return 0;
}
 