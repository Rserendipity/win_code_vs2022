#pragma once
#include "Game.h"

class Chess {
public:
	enum ChessType;
	const char* ChessName[8] = {nullptr, "��","ʿ","��","��","��","��","��"};
	/// <summary>
	/// ��ʾһ������
	/// </summary>
	/// <param name="x"> ������ </param>
	/// <param name="y"> ������ </param>
	/// <param name="ChessType"> ���ӵ����� </param>
	Chess(int x, int y, ChessType type);

	/// <summary>
	/// �ƶ�����
	/// </summary>
	/// <param name="x"> �ƶ���ĺ����� </param>
	/// <param name="y"> �ƶ���������� </param>
	void Move(int x, int y);
private:
	int x;
	int y;
	bool isLive;
	ChessType t;
	IMAGE img;
};

