#pragma once
#include "Game.h"

class Chess {
public:
	enum ChessType;
	const char* ChessName[8] = {nullptr, "将","士","象","马","车","炮","卒"};
	/// <summary>
	/// 显示一个棋子
	/// </summary>
	/// <param name="x"> 横坐标 </param>
	/// <param name="y"> 纵坐标 </param>
	/// <param name="ChessType"> 棋子的类型 </param>
	Chess(int x, int y, ChessType type);

	/// <summary>
	/// 移动棋子
	/// </summary>
	/// <param name="x"> 移动后的横坐标 </param>
	/// <param name="y"> 移动后的纵坐标 </param>
	void Move(int x, int y);
private:
	int x;
	int y;
	bool isLive;
	ChessType t;
	IMAGE img;
};

