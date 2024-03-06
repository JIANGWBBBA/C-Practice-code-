#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//扫雷
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
    printf("-----------扫雷游戏--------------\n");
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
    printf("-----------扫雷游戏--------------\n");
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
        printf("请输入坐标\n");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] == '1')
            {
                printf("中雷了\n");
                Display(mine, row, col);
                break;
            }
            else if (show[x][y] != '*')
                printf("坐标已被占用，请重新选择\n");
            else
            {
                int count = minecount(mine, x, y);
                show[x][y] = count + '0';
                Display(show, row, col);
                win++;
                if (win == row * col - easycount)
                {
                    printf("恭喜你赢了\n");
                    // Display(mine, row, col);
                    break;
                }

            }
        }
        else
            printf("坐标非法请重新输入\n");
    }
}
void game()
{
    char mine[ROWS][COLS] = { 0 };//存放好雷的信息
    char show[ROWS][COLS] = { 0 };//排查雷的信息
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
        printf("请选择>\n");
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
            printf("退出游戏\n");
            break;
        }
        default:
        {
            printf("选择错误");
            break;
        }

        }

    } while (input);
    return 0;
}