#define _CRT_SECURE_NO_WARNINGS

#define ROW 9
#define COL 9
#define ROWS  ROW + 2
#define COLS  COL + 2
#define Easy_Count 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void Setmap(char board[ROWS][COLS], int row, int col);
void FindMap(char map[ROWS][COLS],char show[ROWS][COLS],int row,int col);
int get_map_count(char map[ROWS][COLS], int x, int y);
void empty(char map[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* chenggong);

