#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
void sort(int arr[], int sz)
{
	int i = 0;
	int flag = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			int tmp = 0;
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
int search(int arr[], int input, int sz)
{
	int right = sz - 1;
	int left = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < input)
		{
			left = mid + 1;
		}
		else if (arr[mid] > input)
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return -1;
}
int main()
{
	int arr[10] = { 9,10,2,3,1,8,7,5,6,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort(arr, sz);
	int input = 0;
	scanf("%d", &input);
	int ret = search(arr, input, sz);
	printf("%d", ret);
	return 0;
}