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
	printf("����:>");
	ch = getchar();
	switch (ch)
	{
	case 'W' || 'w':
		printf("��");
		break;
	}

	//int input = 0;
	//do
	//{
	//	menu();
	//	printf("��ѡ��:>");
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		game();
	//		break;
	//	case 0:
	//		printf("�˳�\n");
	//		break;
	//	default:
	//		printf("�����������ѡ��\n");
	//		break;
	//	}
	//} while (input);
	//return 0;
}