#include "game.h"
int DogFall(char arr[ROW][COL], int row, int col)//平局或继续函数
{
	int i = 0;
	int j = 0;
	for (i + 0; i < row; i++)
	{
		for (j + 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 4;
			}
		}
	}
	return 3;
}
void InitBoard(char arr[ROW][COL], int row, int col)//初始化棋盘函数
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void DisplayBoard(char arr[ROW][COL], int row, int col)//打印棋盘函数
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);                   
			if (j < col - 1)
			{
				printf("|");
			}
			if (j == col - 1)
			{
				printf("\n");
			}
		}
		if (i < row - 1)
		{
			for (k = 0; k < col; k++)
			{
				printf("---");
					if (k < col-1)
					{
						printf("|");
					}
					if (k == col-1)
					{
						printf("\n");
					}
					
			}
		}
	}
}
void PlayerMove(char arr[ROW][COL], int row, int col)//玩家走步函数
{
	int x = 0;
	int y = 0;
	printf("请玩家落子!\n");
	while (1)
	{
		again:
		printf("请输入坐标->:");
		scanf("%d %d", &x, &y);
		if (x <= row && x >= 1 && y >= 1 && y <= col)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("坐标被占用！\n");
				goto again;
			}
		}
		else
		{
			getchar();//限制数字检测
			printf("坐标非法！\n");
			goto again;
		}
	}
}
void ComuterMove(char arr[ROW][COL], int row, int col)//AI走步函数
{
	while (1)
	{
		printf("AI走步\n");
	again1:
		int x = rand() % row;
		int y = rand() % col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = 'O';
			break;
		}
		else
		{
			goto again1;
		}
	}
}
char IsWin(char arr[ROW][COL], int row, int col)//判断输赢函数
{ 
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//row=3
	{
			if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2]&&arr[i][0]!=' ')//行相等判断
			{
				return arr[i][0];
			}
	}
	for (i = 0; i < col; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')//列相等判断
		{
			return arr[0][i];
		}
	}
	    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')//左对角线
	    {
		    return arr[0][0];
	    }
	    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2]!=' ')//右对角线
	    {
		    return arr[0][2];
	    }
	    //判定平局
	    if (3 == DogFall(arr, ROW, COL))
	    {
		    return 'F';//平局
	    }
	    return 'C';//继续
}

