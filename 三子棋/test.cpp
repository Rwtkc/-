#include<stdio.h>
#pragma warning(disable:4996)
#include"game.h"
void menu()
{
	printf("******井子棋*********\n");
	printf("******1.play*********\n");
	printf("******2.exit*********\n");
	printf("******3.规则说明*****\n");
}
void game()
{
	int u = 0;
	char ret = 0;
	char board[ROW][COL]={0};//将棋盘初始化为0
	InitBoard(board, ROW, COL);//将棋盘数据初始化为空格
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家移动
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret = IsWin(board, ROW, COL);//判断胜负
		if (ret != 'C')//如果不是继续那么一定有人赢或者平局，如果不是'C'循环不会停止达成循环走步的效果
		{
			break;
		}
		ComuterMove(board, ROW, COL);//AI移动
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret!='C')//如果不是继续那么一定有人赢或者平局
		{
			break;
		}
	}
	if (ret == 'X')
	{
		printf("恭喜玩家胜利\n");
	}
	if (ret == 'O')
	{
		printf("恭喜AI赢\n");
	}
	else if(ret!='O'&& ret != 'X')
	{
		printf("本局平局\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));//AI走步用的随机值（时间戳）
	again:
	menu();
	int n = 0;
	printf("请选择->:");
	scanf("%d", &n);
	switch(n)
	{
	case 1://开始游戏
		game();
		break;
	case 2://游戏退出
		printf("游戏退出！");
		break;
	case 3://规则说明
		printf("玩家走步为'X',AI走步为'O',填写坐标格式为横坐标 空格 纵坐标\n");
		goto again;
	default:
		getchar();//限制数字检测
		printf("请重新选择！\n"); 
		goto again;
		break;
	}
	return 0;
}