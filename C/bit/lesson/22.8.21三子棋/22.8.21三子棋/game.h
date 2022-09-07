#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3


void dispaly_board(char board[ROW][COL], int row, int col);
void init_board(char board[ROW][COL], int row, int col);
void player_move(char board[ROW][COL], int row, int col);
void computer_move(char board[ROW][COL], int row, int col);
char is_win(char board[ROW][COL], int row, int col);