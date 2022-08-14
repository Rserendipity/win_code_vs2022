#include "Game.h"

void menu()
{
	printf("\n");
	printf("****************************\n");
	printf("*****        ɨ��       ****\n");
	printf("*****   ������1����0    ****\n");
	printf("*****  1.play   0.exit  ****\n");
	printf("****************************\n");
	printf("\n");
}

void Game()
{
	//�����հ�����
	char map[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBoard(map, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	//DisplayBoard(map, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//���������
	Setmap(map, ROW, COL);
	//DisplayBoard(map, ROW, COL);
	//ɨ��
	FindMap(map, show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
