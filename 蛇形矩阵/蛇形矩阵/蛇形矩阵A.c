#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[20][20] = { 0 };
	int n = 0;
	scanf("%d", &n);
	int looper = (n + 1) * n / 2;
	int num = 1;
	arr[0][0] = 1;
	int tol = 0;
	int movex = 0;
	int movey = 0;
	int i = 0;
	while (num < looper)
	{
		num++;
		movex++;
		tol++;
		arr[movey][movex] = num;
		for (i = 0; i < tol; i++)
		{
			num++;
			movex--;
			movey++;
			arr[movey][movex] = num;

		}
		num++;
		movey++;
		tol++;
		arr[movey][movex] = num;
		for (i = 0; i < tol; i++)
		{
			movey--;
			movex++;
			num++;
			arr[movey][movex] = num;
		}
	}
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < n - i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}