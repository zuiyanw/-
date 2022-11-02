#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//参数设定参照 qsort函数 *base为数组首元素地址 sz为待比较的元素个数   width为待比较数组每个元素大小


void swip(char*buf1, char*buf2, int width)//bubble_sort()函数中 已经把2个参数强制转换成了 char*
{
	int i = 0;
	for (i = 0; i < width; i++)//针对结构体字符串："abcd"  "efgh"  2组对比的话 因为本身已经被强制转换成了char*
		//所以 buf1这里只对应 字节数所对应的元素 abcd强制转换后有4个字节 buf1="a"
	{
		char tmp = *buf1;//buf1本身就是地址 需要对其解引用 不然只是地址数字交换
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;//a,e交换完  交换b,f 然后c,g; d,h
		buf2++;
	}
	
}

int cmp_int(const void*e1, const void*e2)//参照qsort函数 >为1 ==为0 <为-1
{
	return *(int*)e1 - *(int*)e2;//这个是整型的比较方式 不同对象比较方式 这里可以更改
}


void bubble_sort(void*base, int sz, int width, int(*cmp)(void*e1, void*e2))//地址不确定 所以设置成void* 可以接受任意类型的地址
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)//趟数 以int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 } 为例子
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//配对数 9跟8,7，6,5,4,3,2,1,0依次比较 需要比较9次 下一趟则是8，依次类推
		{
			if (cmp((char*)base + width*j, (char*)base + width*(j + 1)) > 0)//程序员自己设计的比较程序 所返回的结果 -1 0 1
			{                       //因为char*是一个字节 把首元素强制转换为char* 然后再跳width个字节 即转到第二个元素地址处
				swip((char*)base + width*j, (char*)base + width*(j + 1), width);//排序函数
				//因为要排序 需要把2个参数上传 参数类型需要对照cmp中的类型
			}
		}
	}
}


void test4()
{
	int arr[] = { 9, 8, 3, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);//冒泡函数  cmp为比较函数
	int i = 0;                                //cmp要注意先声明再引用
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

struct stu  //结构体 先声明,再使用
{
	char name[20]; //数组个数需要给到 - 创建结构体数组
	int age;
	
};

int cmp_age(const void*e1, const void*e2)   //age是int型
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;  //voi*e1需要先强制转换为结构体指针
}

int cmp_name(const void*e1, const void*e2)   //age是int型
{   //比较名字就是比较字符串  
	return strcmp( ((struct stu*)e1)->name, ((struct stu*)e2)->name );  //voi*e1需要先强制转换为结构体指针
}

void print_(struct stu* p, int sz)//指针形式查找  
{
	int i = 0;
	for (i = 0; i < sz; i++)
		{
			printf("%d ", (p+i)->age); //结构体寻找对象格式
		}
} 

void test3()
{
	struct stu s[3] = { { "msan", 20 }, { "au", 30 }, { "lilei", 5 } };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_age);//cmp要注意先声明再引用

	print_(s, sz);//sturct stu s的首元素地址
	                              
	//for (i = 0; i < sz; i++)
	//{
	//	printf("%s ", s[i].name); //结构体寻找对象格式  非指针形式
	//}
	print_(s, sz);//sturct stu s的首元素地址
}

int main()//指向函数指针数组 的指针
{
	//test1();//冒泡排序
	//test5();
	//test2();
	test3();
	//test4();
	return 0;
}
 