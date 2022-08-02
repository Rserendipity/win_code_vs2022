#include "Game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
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

void Setmap(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_Count;
	while (count)
	{
		int x = rand() % ROW + 1;//1~9之间的数
		int y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}	

void FindMap(char map[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int chenggong = 0;
	while (chenggong < row * col - Easy_Count)
	{
		printf("请输入排查雷的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (map[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(map, row, col);
				break;
			}
			else
			{
				int count = get_map_count(map, x, y);
				show[x][y] = count + '0';
				if (count == 0)
				{
					cheak(map,show,x,y,&chenggong);
				}
				DisplayBoard(show, row, col);
				chenggong++;

			}
		}
		else
		{
			printf("请输入合法坐标！\n");
		}
		if (chenggong == row * col - Easy_Count)
		{
			printf("恭喜排雷成功！\n");
			DisplayBoard(map, ROW, COL);
		}
	}
}
int get_map_count(char map[ROWS][COLS], int x, int y)
{
	return map[x - 1][y] +
		map[x - 1][y - 1] +
		map[x][y - 1] +
		map[x + 1][y - 1] +
		map[x + 1][y] +
		map[x + 1][y + 1] +
		map[x][y + 1] +
		map[x - 1][y + 1] - 8 * '0';
}

void cheak(char map[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* chenggong)
{
	//边界判断,如果在边界就不要再递归了,显示当前的值
	if (x == 1)
	{

	}
	else if (y == 1)
	{

	}
	else if (x == ROW)
	{

	}
	else if (y == COL)
	{

	}
	else if (x > 1 && y > 1 && x < ROW-1 && y < COL-1)
	{

	}
}