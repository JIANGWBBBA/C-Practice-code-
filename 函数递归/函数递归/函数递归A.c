#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //函数递归 嵌套
void repeat(unsigned int num)
{
    if (num > 9)
    {
        repeat(num / 10);
    }
    printf("%u ", num % 10);
}
int main()
{
    unsigned int num = 0;
    scanf("%u ", &num);
    repeat(num);
    return 0;
}
#include<stdio.h> //模拟实现strlen
int len(char* p)
{
    if (*p != '\0')
        return 1 + len(p + 1);
    else
        return 0;
}
int main()
{
    char arr[] = "abc";
    printf("%d \n", len(arr));
    return 0;
}
#include <stdio.h>//斐波那契函数 1 1 2 3 5 8...
int fib(int n)
{
    if (n <= 2)
        return 1;
    else
        return fib(n - 2) + fib(n - 1);
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int ret = fib(n);
    printf("%d", ret);
    return 0;
}
#include <string.h>*/// 逆序
void reverse(char arr[])
{
    if (*arr != '\0')
    {
        reverse(arr + 1);
    }
    printf("%c", *arr);
}
int main()
{
    char arr[] = "abcdef";
    reverse(arr);
    return 0;
}

void reverse(char* str)
{
    char tmp = *str;
    int len = strlen(str);
    *str = *(str + len - 1);
    *(str + len - 1) = '\0';
    if (strlen(str + 1) >= 2)
    {
        reverse(str + 1);
    }
    *(str + len - 1) = tmp;
}
int main()
{
    char arr[] = "abcdefg";
    reverse(arr);
    printf("%s\n", arr);
    return 0;
}
void reverse(char arr[], int right, int left)
{
    char tmp = arr[right];
    arr[right] = arr[left];
    arr[left] = tmp;
    if (left < right)
        reverse(arr, right - 1, left + 1);
}
int main()
{
    char arr[] = "abcdefg";
    int right = strlen(arr) - 1;
    int left = 0;
    reverse(arr, right, left);
    printf("%s", arr);
    return 0;
}
#include <stdio.h>//计算每一位的和
int fun(int num)
{

    if (num > 9)
        return fun(num / 10) + num % 10;

    else
        return num;


}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int ret = fun(n);
    printf("%d", ret);
    return 0;

}
#include <stdio.h> //计算指数 
double pow(int n, int k)
{
    if (k > 0)
        return n * pow(n, k - 1);
    else if (k == 0)
        return 1;
    else
        return 1.0 / pow(n, -k);
}
int main()
{

    int n = 0;
    int k = 0;

    scanf("%d %d", &n, &k);
    double ret = pow(n, k);
    printf("%lf", ret);
    return 0;
}
#include <stdio.h> //计算小小乐走台阶的方法数
int fib(int n)
{
    if (n <= 2)
        return n;
    if (n > 2)
        return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int r = fib(n);
    printf("%d", r);
    return 0;
}