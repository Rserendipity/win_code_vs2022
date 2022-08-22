#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//列号
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void set_mine(char mine[ROWS][COLS], int row, int col)
{
	//布置10个雷
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1]-8*'0');
}

void find(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int* win)
{
	//坐标合法 x,y
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		// 该点坐标是雷
		if (mine[x][y] == '1')
			;
		// 没有被排查过 
		else if (show[x][y] == '*')
		{
			int ret = get_mine_count(mine, x, y);
			show[x][y] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x, y, win);
		}
	}

	//坐标合法 x,y-1
	if (x >= 1 && x <= row && y - 1 >= 1 && y - 1 <= col)
	{
		// 该点坐标是雷
		if (mine[x][y - 1] == '1')
			;
		// 没有被排查过 
		else if (show[x][y - 1] == '*')
		{
			int ret = get_mine_count(mine, x, y - 1);
			show[x][y - 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x, y - 1, win);
		}
	}

	//坐标合法 x,y+1
	if (x >= 1 && x <= row && y + 1 >= 1 && y + 1 <= col)
	{
		// 该点坐标是雷
		if (mine[x][y + 1] == '1')
			;
		// 没有被排查过 
		else if (show[x][y + 1] == '*')
		{
			int ret = get_mine_count(mine, x, y + 1);
			show[x][y + 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x, y + 1, win);
		}
	}


	//坐标合法 x-1,y
	if (x - 1 >= 1 && x - 1 <= row && y >= 1 && y <= col)
	{
		// 该点坐标是雷
		if (mine[x - 1][y] == '1')
			;
		// 没有被排查过 
		else if (show[x - 1][y] == '*')
		{
			int ret = get_mine_count(mine, x - 1, y);
			show[x - 1][y] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x - 1, y, win);
		}
	}

	//坐标合法 x-1,y-1
	if (x - 1 >= 1 && x - 1 <= row && y - 1 >= 1 && y - 1 <= col)
	{
		// 该点坐标是雷
		if (mine[x - 1][y - 1] == '1')
			;
		// 没有被排查过 
		else if (show[x - 1][y - 1] == '*')
		{
			int ret = get_mine_count(mine, x - 1, y - 1);
			show[x - 1][y - 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x - 1, y - 1, win);
		}
	}

	//坐标合法 x-1,y+1
	if (x - 1 >= 1 && x - 1 <= row && y + 1 >= 1 && y + 1 <= col)
	{
		// 该点坐标是雷
		if (mine[x - 1][y + 1] == '1')
			;
		// 没有被排查过 
		else if (show[x - 1][y + 1] == '*')
		{
			int ret = get_mine_count(mine, x - 1, y + 1);
			show[x - 1][y + 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x - 1, y + 1, win);
		}
	}


	//坐标合法 x+1,y
	if (x + 1 >= 1 && x + 1 <= row && y >= 1 && y <= col)
	{
		// 该点坐标是雷
		if (mine[x + 1][y] == '1')
			;
		// 没有被排查过 
		else if (show[x + 1][y] == '*')
		{
			int ret = get_mine_count(mine, x + 1, y);
			show[x + 1][y] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x + 1, y, win);
		}
	}

	//坐标合法 x+1,y-1
	if (x + 1 >= 1 && x + 1 <= row && y - 1 >= 1 && y - 1 <= col)
	{
		// 该点坐标是雷
		if (mine[x + 1][y - 1] == '1')
			;
		// 没有被排查过 
		else if (show[x + 1][y - 1] == '*')
		{
			int ret = get_mine_count(mine, x + 1, y - 1);
			show[x + 1][y - 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x + 1, y - 1, win);
		}
	}

	//坐标合法 x+1,y+1
	if (x + 1 >= 1 && x + 1 <= row && y + 1 >= 1 && y + 1 <= col)
	{
		// 该点坐标是雷
		if (mine[x + 1][y + 1] == '1')
			;
		// 没有被排查过 
		else if (show[x + 1][y + 1] == '*')
		{
			int ret = get_mine_count(mine, x + 1, y + 1);
			show[x + 1][y + 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x + 1, y + 1, win);
		}
	}

}

void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (win<row*col- EASY_COUNT)
	{
		printf("请输入要排查雷的坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标没有被排查过
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					display_board(mine, ROW, COL);
					break;
				}
				else
				{
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';
					win++;
					if (count == 0)
					{
						find(mine, show, row, col, x, y, &win);
					}
					system("cls");
					display_board(show, ROW, COL);
				}
			}
			else
			{
				printf("该坐标已经被排查过了\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		display_board(mine, ROW, COL);
	}
}

