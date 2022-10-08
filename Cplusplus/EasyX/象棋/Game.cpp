#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

static void initBoard()
{
	IMAGE img;
	loadimage(&img, "./pic/ChessBoard.jpg");
	initgraph(img.getwidth(), img.getheight());
	putimage(0, 0, &img);
}


void InitGame()
{
	
}



