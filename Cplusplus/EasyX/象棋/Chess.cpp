#include "Chess.h"
enum Chess::ChessType {
	non      = 0,  // ��
	king     = 1,  // ��
	scholar  = 2,  // ʿ
	elephant = 3,  // ��
	horse    = 4,  // ��
	car      = 5,  // ��
	cannon   = 6,  // ��
	soldier  = 7   // ��
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
