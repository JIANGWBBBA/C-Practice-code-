#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//ɨ��
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easycount 10
void Initboard(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            mine[i][j] = '0';
        }
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            show[i][j] = '*';
        }
    }

}
void Display(char arr[ROWS][COLS], int row, int col)
{
    printf("-----------ɨ����Ϸ--------------\n");
    int i = 0;
    int j = 0;
    for (j = 0; j <= col; j++)
    {

        printf("%d ", j);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", arr[i][j]);
        }printf("\n");
    }
    printf("-----------ɨ����Ϸ--------------\n");
}
void Setmine(char mine[ROWS][COLS], int row, int col)
{
    int count = easycount;

    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (mine[x][y] == '0')
        {
            mine[x][y] = '1';
            count--;
        }
    }
}
int minecount(char mine[ROWS][COLS], int x, int y)
{
    return

        mine[x - 1][y - 1] +
        mine[x - 1][y] +
        mine[x - 1][y + 1] +
        mine[x][y - 1] +
        mine[x][y + 1] +
        mine[x + 1][y - 1] +
        mine[x + 1][y] +
        mine[x + 1][y + 1] - 8 * '0';

}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int win = 0;
    int x = 0;
    int y = 0;
    while (1)
    {
        printf("����������\n");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] == '1')
            {
                printf("������\n");
                Display(mine, row, col);
                break;
            }
            else if (show[x][y] != '*')
                printf("�����ѱ�ռ�ã�������ѡ��\n");
            else
            {
                int count = minecount(mine, x, y);
                show[x][y] = count + '0';
                Display(show, row, col);
                win++;
                if (win == row * col - easycount)
                {
                    printf("��ϲ��Ӯ��\n");
                    // Display(mine, row, col);
                    break;
                }

            }
        }
        else
            printf("����Ƿ�����������\n");
    }
}
void game()
{
    char mine[ROWS][COLS] = { 0 };//��ź��׵���Ϣ
    char show[ROWS][COLS] = { 0 };//�Ų��׵���Ϣ
    Initboard(mine, show, ROWS, COLS);
    Setmine(mine, ROW, COL);
    Display(mine, ROW, COL);
    Display(show, ROW, COL);
    Findmine(mine, show, ROW, COL);

}
int main()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        printf("********************\n");
        printf("********1.play******\n");
        printf("********0.exit******\n");
        printf("********************\n");
        printf("��ѡ��>\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
        {
            game();
            break;
        }
        case 0:
        {
            printf("�˳���Ϸ\n");
            break;
        }
        default:
        {
            printf("ѡ�����");
            break;
        }

        }

    } while (input);
    return 0;
}