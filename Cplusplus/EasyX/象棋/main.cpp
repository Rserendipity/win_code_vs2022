#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <graphics.h> 
#include <conio.h>
using namespace std;

int main()
{
	IMAGE img;
	loadimage(&img, "./pic/ChessBoard.jpg");
	initgraph(img.getwidth(), img.getheight());
	putimage(0, 0, &img);


	getchar();
	return 0;
}