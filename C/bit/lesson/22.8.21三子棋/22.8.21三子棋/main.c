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
	// 初始化
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);
	dispaly_board(board, ROW, COL);
	// 玩家赢 *
	// 电脑赢 #
	// 平局   P
	// 继续   C
	char ch = 0;
	while (1)
	{
		// 玩家赢
		player_move(board, ROW, COL);
		
		ch = is_win(board, ROW, COL);
		dispaly_board(board, ROW, COL);
		if (ch != 'C')
			break; 
		computer_move(board, ROW, COL);
		
		ch = is_win(board, ROW, COL);
		dispaly_board(board, ROW, COL);
		if (ch != 'C')
			break;
	}
	if (ch == '*')
		printf("玩家赢\n");
	else if (ch == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");
}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("输入错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}