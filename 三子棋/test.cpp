#include<stdio.h>
#pragma warning(disable:4996)
#include"game.h"
void menu()
{
	printf("******������*********\n");
	printf("******1.play*********\n");
	printf("******2.exit*********\n");
	printf("******3.����˵��*****\n");
}
void game()
{
	int u = 0;
	char ret = 0;
	char board[ROW][COL]={0};//�����̳�ʼ��Ϊ0
	InitBoard(board, ROW, COL);//���������ݳ�ʼ��Ϊ�ո�
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (1)
	{
		PlayerMove(board, ROW, COL);//����ƶ�
		DisplayBoard(board, ROW, COL);//��ӡ����
		ret = IsWin(board, ROW, COL);//�ж�ʤ��
		if (ret != 'C')//������Ǽ�����ôһ������Ӯ����ƽ�֣��������'C'ѭ������ֹͣ���ѭ���߲���Ч��
		{
			break;
		}
		ComuterMove(board, ROW, COL);//AI�ƶ�
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret!='C')//������Ǽ�����ôһ������Ӯ����ƽ��
		{
			break;
		}
	}
	if (ret == 'X')
	{
		printf("��ϲ���ʤ��\n");
	}
	if (ret == 'O')
	{
		printf("��ϲAIӮ\n");
	}
	else if(ret!='O'&& ret != 'X')
	{
		printf("����ƽ��\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));//AI�߲��õ����ֵ��ʱ�����
	again:
	menu();
	int n = 0;
	printf("��ѡ��->:");
	scanf("%d", &n);
	switch(n)
	{
	case 1://��ʼ��Ϸ
		game();
		break;
	case 2://��Ϸ�˳�
		printf("��Ϸ�˳���");
		break;
	case 3://����˵��
		printf("����߲�Ϊ'X',AI�߲�Ϊ'O',��д�����ʽΪ������ �ո� ������\n");
		goto again;
	default:
		getchar();//�������ּ��
		printf("������ѡ��\n"); 
		goto again;
		break;
	}
	return 0;
}