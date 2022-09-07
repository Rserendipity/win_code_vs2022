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
	// ��ʼ��
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);
	dispaly_board(board, ROW, COL);
	// ���Ӯ *
	// ����Ӯ #
	// ƽ��   P
	// ����   C
	char ch = 0;
	while (1)
	{
		// ���Ӯ
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
		printf("���Ӯ\n");
	else if (ch == '#')
		printf("����Ӯ\n");
	else
		printf("ƽ��\n");
}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}