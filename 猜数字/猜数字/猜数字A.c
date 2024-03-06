#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void menu()
{
    printf("请选择\n");
}
void game()
{
    int guess = 0;
    int ret = rand() % 100 + 1;
    while (1)
    {
        scanf("%d", &guess);
        if (guess < ret)
            printf("猜小了\n");
        else if (guess > ret)
            printf("猜大了\n");
        else
        {
            printf("恭喜你猜对了\n");
            break;
        }
    }
}
int main()
{
    srand((unsigned int)time(NULL));

    int choice = 0;
    do
    {
        printf("****************\n");
        printf("*****1.play*****\n");
        printf("*****0.exit*****\n");
        printf("****************\n");
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("请输入数字\n");
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }

    } while (choice);

    return 0;
}