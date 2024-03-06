#define _CRT_SECURE_NO_WARNINGS
int main()//ÕÒÖÚÊı
{
    int a = 0;
    scanf("%d", &a);
    int arr[10] = { 0 };
    int i = 0;
    int num = 0;
    for (i = 0; i < a; i++)
    {
        scanf("%d", &num);
        arr[num]++;
    }
    int ans = 0;
    int x = 0;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] > x)
        {
            ans = i;
            x = arr[i];
        }
    }
    printf("%d\n", ans);
    printf("%d\n", x);
    return 0;
}