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
	//�к�
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
	//����10����
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
	//����Ϸ� x,y
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		// �õ���������
		if (mine[x][y] == '1')
			;
		// û�б��Ų�� 
		else if (show[x][y] == '*')
		{
			int ret = get_mine_count(mine, x, y);
			show[x][y] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x, y, win);
		}
	}

	//����Ϸ� x,y-1
	if (x >= 1 && x <= row && y - 1 >= 1 && y - 1 <= col)
	{
		// �õ���������
		if (mine[x][y - 1] == '1')
			;
		// û�б��Ų�� 
		else if (show[x][y - 1] == '*')
		{
			int ret = get_mine_count(mine, x, y - 1);
			show[x][y - 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x, y - 1, win);
		}
	}

	//����Ϸ� x,y+1
	if (x >= 1 && x <= row && y + 1 >= 1 && y + 1 <= col)
	{
		// �õ���������
		if (mine[x][y + 1] == '1')
			;
		// û�б��Ų�� 
		else if (show[x][y + 1] == '*')
		{
			int ret = get_mine_count(mine, x, y + 1);
			show[x][y + 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x, y + 1, win);
		}
	}


	//����Ϸ� x-1,y
	if (x - 1 >= 1 && x - 1 <= row && y >= 1 && y <= col)
	{
		// �õ���������
		if (mine[x - 1][y] == '1')
			;
		// û�б��Ų�� 
		else if (show[x - 1][y] == '*')
		{
			int ret = get_mine_count(mine, x - 1, y);
			show[x - 1][y] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x - 1, y, win);
		}
	}

	//����Ϸ� x-1,y-1
	if (x - 1 >= 1 && x - 1 <= row && y - 1 >= 1 && y - 1 <= col)
	{
		// �õ���������
		if (mine[x - 1][y - 1] == '1')
			;
		// û�б��Ų�� 
		else if (show[x - 1][y - 1] == '*')
		{
			int ret = get_mine_count(mine, x - 1, y - 1);
			show[x - 1][y - 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x - 1, y - 1, win);
		}
	}

	//����Ϸ� x-1,y+1
	if (x - 1 >= 1 && x - 1 <= row && y + 1 >= 1 && y + 1 <= col)
	{
		// �õ���������
		if (mine[x - 1][y + 1] == '1')
			;
		// û�б��Ų�� 
		else if (show[x - 1][y + 1] == '*')
		{
			int ret = get_mine_count(mine, x - 1, y + 1);
			show[x - 1][y + 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x - 1, y + 1, win);
		}
	}


	//����Ϸ� x+1,y
	if (x + 1 >= 1 && x + 1 <= row && y >= 1 && y <= col)
	{
		// �õ���������
		if (mine[x + 1][y] == '1')
			;
		// û�б��Ų�� 
		else if (show[x + 1][y] == '*')
		{
			int ret = get_mine_count(mine, x + 1, y);
			show[x + 1][y] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x + 1, y, win);
		}
	}

	//����Ϸ� x+1,y-1
	if (x + 1 >= 1 && x + 1 <= row && y - 1 >= 1 && y - 1 <= col)
	{
		// �õ���������
		if (mine[x + 1][y - 1] == '1')
			;
		// û�б��Ų�� 
		else if (show[x + 1][y - 1] == '*')
		{
			int ret = get_mine_count(mine, x + 1, y - 1);
			show[x + 1][y - 1] = ret + '0';
			*win += 1;
			if (ret == 0)
				find(mine, show, row, col, x + 1, y - 1, win);
		}
	}

	//����Ϸ� x+1,y+1
	if (x + 1 >= 1 && x + 1 <= row && y + 1 >= 1 && y + 1 <= col)
	{
		// �õ���������
		if (mine[x + 1][y + 1] == '1')
			;
		// û�б��Ų�� 
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
		printf("������Ҫ�Ų��׵�����:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����û�б��Ų��
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
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
				printf("�������Ѿ����Ų����\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		display_board(mine, ROW, COL);
	}
}

