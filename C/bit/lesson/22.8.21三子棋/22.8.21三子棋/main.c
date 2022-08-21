#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("**************\n");
	printf("*** 1.play ***\n");
	printf("*** 0.exit ***\n");
	printf("**************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);
	dispaly_board(board, ROW, COL);

}

int main()
{

	char ch;
	printf("输入:>");
	ch = getchar();
	switch (ch)
	{
	case 'W' || 'w':
		printf("上");
		break;
	}

	//int input = 0;
	//do
	//{
	//	menu();
	//	printf("请选择:>");
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		game();
	//		break;
	//	case 0:
	//		printf("退出\n");
	//		break;
	//	default:
	//		printf("输入错误，重新选择\n");
	//		break;
	//	}
	//} while (input);
	//return 0;
}