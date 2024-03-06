#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//������
#include <stdlib.h>
#include <time.h>
#define ROW 5 
#define COL 5
void Initboard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void Display(char board[ROW][COL], int row, int col)
{
    int i = 0;

    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
        }
        printf("\n");
        if (i < row - 1)
        {
            int j = 0;
            for (j = 0; j < row; j++)
            {
                printf("---");
                if (j < col - 1)
                    printf("|");
            }
            printf("\n");
        }
    }
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
    printf("�������>\n");
    printf("����������\n");
    int x = 0;
    int y = 0;
    while (1)
    {
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
                printf("�����ѱ�ռ��\n");
        }
        else
            printf("����Ƿ�������������\n");
    }
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("��������>\n");
    while (1)
    {
        x = rand() % row;//���� 0-2
        y = rand() % col;//����0 -2
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}
int Isfull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}
char Ifwin(char board[ROW][COL], int row, int col)//'*'���Ӯ '#'����Ӯ 'Q'ƽ�� 'a'����                 
{
    //��
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 1] != ' ')
            {
                return board[i][j + 1];
                break;
            }
        }
    }
    //��
    for (j = 0; j < col; j++)
    {
        for (i = 0; i < row; i++)
        {
            if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 1][j] != ' ')
            {
                return board[i + 1][j];
                break;
            }
        }
    }
    //�Խ���
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 1][j + 1] != ' ')
            {
                return board[i + 1][j + 1];
                break;
            }
        }
    }

    if (Isfull(board, ROW, COL))
    {
        return 'Q';
    }
    return 0;
}
void game()
{
    char ret = 0;
    srand((unsigned int)time(NULL));
    char board[ROW][COL] = { 0 };
    Initboard(board, ROW, COL);
    Display(board, ROW, COL);
    while (1)
    {
        PlayerMove(board, ROW, COL);
        ret = Ifwin(board, ROW, COL);


        Display(board, ROW, COL);
        if (ret == '*')
        {
            printf("���Ӯ\n");
            break;
        }
        if (ret == 'Q')
        {
            printf("ƽ��\n");
            break;
        }
        ComputerMove(board, ROW, COL);
        Display(board, ROW, COL);
        ret = Ifwin(board, ROW, COL);
        if (ret == '#')
        {
            printf("����Ӯ\n");
            break;
        }
        if (ret == 'Q')
        {
            printf("ƽ��\n");
            break;
        }




    }

}
int main()
{

    int input = 0;

    do
    {
        printf("******************\n");
        printf("******1.play******\n");
        printf("******0.exit******\n");
        printf("******************\n");
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
            break; }
        default:
            printf("�����������ѡ��\n");
        }
    } while (input);
    return 0;
}