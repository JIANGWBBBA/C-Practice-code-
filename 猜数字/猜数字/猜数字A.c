#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void menu()
{
    printf("��ѡ��\n");
}
void game()
{
    int guess = 0;
    int ret = rand() % 100 + 1;
    while (1)
    {
        scanf("%d", &guess);
        if (guess < ret)
            printf("��С��\n");
        else if (guess > ret)
            printf("�´���\n");
        else
        {
            printf("��ϲ��¶���\n");
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
            printf("����������\n");
            game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("ѡ�����\n");
            break;
        }

    } while (choice);

    return 0;
}