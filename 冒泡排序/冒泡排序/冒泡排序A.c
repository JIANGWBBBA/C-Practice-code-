#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//冒泡排序
void bubble_sort(int arr[], int sz)
{
    int n = 0;
    for (n = 0; n < sz - 1; n++)
    {
        int j = 0;
        for (j = 0; j < sz - 1 - n; j++)
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
    }
}
int main()
{
    int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, sz);
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);

    }
    return 0;
}
#include <stdio.h>//冒泡排序进阶
int cmp_by_num(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, int sz, int width, int (*cmp_by_num)(const void* e1, const void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp_by_num((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_by_num);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
/*#include <stdio.h>*/// qsort 
qsort(void* base  起始位置
	size_t num  元素个数
	size_t width   字节大小
	int(*cmp)(const void* e1, const void* e2)  函数指针 - 比较函数
)
int cmp(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);   //  qsort 定义:    <0  小于 =0 等于 >0 大于
}
int main()
{
	int arr[10] = { 10,8,2,3,4,5,6,1,9,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
struct stu
{
	char name[20];
	int age;
};
int main()
{
	struct stu s[] = { {"lisi",16},{"wangwu",17},{"zhangsan",18} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_by_name);

	return 0;
}