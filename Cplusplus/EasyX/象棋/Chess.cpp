#include "Chess.h"
enum Chess::ChessType {
	non      = 0,  // 空
	king     = 1,  // 将
	scholar  = 2,  // 士
	elephant = 3,  // 象
	horse    = 4,  // 马
	car      = 5,  // 车
	cannon   = 6,  // 炮
	soldier  = 7   // 卒
};

Chess::Chess(int x, int y, ChessType type)
{
	if (ChessName[type] == nullptr)
	{
		this->isLive = false;
		return;
	}
	
	this->x = x;
	this->y = y;
	this->isLive = true;
	this->t = type;
}

void Chess::Move(int x, int y)
{

}
