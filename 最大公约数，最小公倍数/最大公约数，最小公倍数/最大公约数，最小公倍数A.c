#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max(int, int);
int min(int, int);
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int ret1 = max(m, n);
	int ret2 = min(m, n,ret1);
	printf("最大公约数 = %d \n 最小公倍数 = %d", ret1, ret2);
	return 0;
}
int max(int x, int y)
{
	int r = 0;
	while (x%y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return y;
}
int min(int x, int y,int max)
{
	return x * y / max;
}