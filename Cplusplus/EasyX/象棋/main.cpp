#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

int main()
{
	Chess* chessArray = InitGame();
	
	int winnerFlag = 0;
	while (1)
	{
		RedPlayerMove(chessArray);  // ��ɫ����ƶ�

		winnerFlag = IsWin(chessArray);
		if (winnerFlag != 0)
			break;
		
		BlackPlayerMove(chessArray); // ��ɫ����ƶ�
		
		winnerFlag = IsWin(chessArray);
		if (winnerFlag != 0)
			break;
	}
	WhoIsWinner(winnerFlag); // ��ʾ˭Ӯ��
	getchar();
	return 0;
}