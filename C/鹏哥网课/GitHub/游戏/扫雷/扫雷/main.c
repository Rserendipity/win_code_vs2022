#include "Game.h"

void menu()
{
	printf("\n");
	printf("****************************\n");
	printf("*****        扫雷       ****\n");
	printf("*****   请输入1或者0    ****\n");
	printf("*****  1.play   0.exit  ****\n");
	printf("****************************\n");
	printf("\n");
}

void Game()
{
	//创建空白数组
	char map[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(map, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(map, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//随机生成雷
	Setmap(map, ROW, COL);
	//DisplayBoard(map, ROW, COL);
	//扫雷
	FindMap(map, show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("退出游戏\n");
		default:
			printf("选择错误！\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
