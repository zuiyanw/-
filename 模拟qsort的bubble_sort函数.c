#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//�����趨���� qsort���� *baseΪ������Ԫ�ص�ַ szΪ���Ƚϵ�Ԫ�ظ���   widthΪ���Ƚ�����ÿ��Ԫ�ش�С


void swip(char*buf1, char*buf2, int width)//bubble_sort()������ �Ѿ���2������ǿ��ת������ char*
{
	int i = 0;
	for (i = 0; i < width; i++)//��Խṹ���ַ�����"abcd"  "efgh"  2��ԱȵĻ� ��Ϊ�����Ѿ���ǿ��ת������char*
		//���� buf1����ֻ��Ӧ �ֽ�������Ӧ��Ԫ�� abcdǿ��ת������4���ֽ� buf1="a"
	{
		char tmp = *buf1;//buf1������ǵ�ַ ��Ҫ��������� ��Ȼֻ�ǵ�ַ���ֽ���
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;//a,e������  ����b,f Ȼ��c,g; d,h
		buf2++;
	}
	
}

int cmp_int(const void*e1, const void*e2)//����qsort���� >Ϊ1 ==Ϊ0 <Ϊ-1
{
	return *(int*)e1 - *(int*)e2;//��������͵ıȽϷ�ʽ ��ͬ����ȽϷ�ʽ ������Ը���
}


void bubble_sort(void*base, int sz, int width, int(*cmp)(void*e1, void*e2))//��ַ��ȷ�� �������ó�void* ���Խ����������͵ĵ�ַ
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)//���� ��int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 } Ϊ����
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//����� 9��8,7��6,5,4,3,2,1,0���αȽ� ��Ҫ�Ƚ�9�� ��һ������8����������
		{
			if (cmp((char*)base + width*j, (char*)base + width*(j + 1)) > 0)//����Ա�Լ���ƵıȽϳ��� �����صĽ�� -1 0 1
			{                       //��Ϊchar*��һ���ֽ� ����Ԫ��ǿ��ת��Ϊchar* Ȼ������width���ֽ� ��ת���ڶ���Ԫ�ص�ַ��
				swip((char*)base + width*j, (char*)base + width*(j + 1), width);//������
				//��ΪҪ���� ��Ҫ��2�������ϴ� ����������Ҫ����cmp�е�����
			}
		}
	}
}


void test4()
{
	int arr[] = { 9, 8, 3, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);//ð�ݺ���  cmpΪ�ȽϺ���
	int i = 0;                                //cmpҪע��������������
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

struct stu  //�ṹ�� ������,��ʹ��
{
	char name[20]; //���������Ҫ���� - �����ṹ������
	int age;
	
};

int cmp_age(const void*e1, const void*e2)   //age��int��
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;  //voi*e1��Ҫ��ǿ��ת��Ϊ�ṹ��ָ��
}

int cmp_name(const void*e1, const void*e2)   //age��int��
{   //�Ƚ����־��ǱȽ��ַ���  
	return strcmp( ((struct stu*)e1)->name, ((struct stu*)e2)->name );  //voi*e1��Ҫ��ǿ��ת��Ϊ�ṹ��ָ��
}

void print_(struct stu* p, int sz)//ָ����ʽ����  
{
	int i = 0;
	for (i = 0; i < sz; i++)
		{
			printf("%d ", (p+i)->age); //�ṹ��Ѱ�Ҷ����ʽ
		}
} 

void test3()
{
	struct stu s[3] = { { "msan", 20 }, { "au", 30 }, { "lilei", 5 } };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_age);//cmpҪע��������������

	print_(s, sz);//sturct stu s����Ԫ�ص�ַ
	                              
	//for (i = 0; i < sz; i++)
	//{
	//	printf("%s ", s[i].name); //�ṹ��Ѱ�Ҷ����ʽ  ��ָ����ʽ
	//}
	print_(s, sz);//sturct stu s����Ԫ�ص�ַ
}

int main()//ָ����ָ������ ��ָ��
{
	//test1();//ð������
	//test5();
	//test2();
	test3();
	//test4();
	return 0;
}
 