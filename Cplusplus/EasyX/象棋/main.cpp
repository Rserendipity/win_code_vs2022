#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

int main()
{
	Chess* chessArray = InitGame();
	
	int winnerFlag = 0;
	while (1)
	{
		RedPlayerMove(chessArray);  // 红色玩家移动

		winnerFlag = IsWin(chessArray);
		if (winnerFlag != 0)
			break;
		
		BlackPlayerMove(chessArray); // 黑色玩家移动
		
		winnerFlag = IsWin(chessArray);
		if (winnerFlag != 0)
			break;
	}
	WhoIsWinner(winnerFlag); // 显示谁赢了
	getchar();
	return 0;
}