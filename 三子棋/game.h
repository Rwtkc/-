#define ROW 3
#define COL 3
#include <stdio.h>
#pragma warning(disable:4996)
#include <time.h>
#include <stdlib.h>
void InitBoard(char arr[ROW][COL], int row, int col);//函数声明
void DisplayBoard(char arr[ROW][COL], int row, int col);
void DisplayBoard(char arr[ROW][COL], int row, int col);
void PlayerMove(char arr[ROW][COL], int row,int col);
void ComuterMove(char arr[ROW][COL], int row, int col);
char IsWin(char arr[ROW][COL], int row, int col);
int DogFall(char arr[ROW][COL], int row, int col);
//ret
//'X'玩家赢
//'O'电脑赢
//'C'继续
//'F'平局