#define _CRT_SECURE_NO_WARNINGS
牛顿迭代法: x1 = x0 - (f(x0) / f'(x0))
#include <stdio.h>
#include <math.h>
	int main()
{
	double a = -1, b = 10, f1, f2, f, x;
	f1 = 2 * pow(a, 3) - 4 * pow(a, 2) + 3 * a - 6;
	f2 = 2 * pow(b, 3) - 4 * pow(b, 2) + 3 * b - 6;
	do
	{
		x = (a + b) / 2;
		f = 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
		if (f * f1 < 0)
		{
			b = x;
			f2 = f;
		}
		else
		{
			a = x;
			f1 = f;
		}
	} while (fabs(f) >= 1e-6);
	printf("%.2lf", x);
	return 0;
}
int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	double f1 = 0, f2 = 0;
	double x1 = 1, x0 = 0;
	do
	{
		x0 = x1;
		f1 = a * pow(x0, 3) + b * pow(x0, 2) + c * x0 - d;
		f2 = 3 * a * pow(x0, 2) + 2 * b * x0 + c;
		x1 = x0 - (f1 / f2);
	} while (fabs(x1 - x0) >= 1e-6);
	printf("%lf", x1);
	return 0;
}
double My_sqrt(double n, double e)
{
	double x1 = n, x0 = 0;
	do {
		x0 = x1;
		double f1 = x0 * x0 - n;
		double f2 = 2 * x0;
		x1 = x0 - f1 / f2;
	} while (fabs(x1 - x0) >= e);

	return x1;
}
int main()
{
	double x = 0, e = 0;
	scanf("%lf", &x, &e);
	double ret = My_sqrt(x, e);
	printf("%lf", ret);
	return 0;
}
double getsolve(int a, int b, int c)
{
	double f1, f2, x1, x0;
	x1 = 1;
	do
	{
		x0 = x1;
		f1 = a * x0 * x0 + b * x0 + c;
		f2 = 2 * a * x0 + b;
		x1 = x0 - f1 / f2;

	} while (fabs(x1 - x0) >= 1e-6);
	return x1;
}
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (b * b - 4 * a * c < 0)
	{
		printf("无根\n");
	}
	else if (b * b - 4 * a * c == 0)
	{
		double ret = getsolve(a, b, c);
		printf("%.2lf", ret);
	}
	else
	{

	}

	return 0;
}