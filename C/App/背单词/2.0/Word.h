#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Word
{
public:
	const int MAX_WORD_SIZE = 4449;
	Word();
	string** GetCh();
	~Word();
private:
	static int current;
	string* ch[4];
	string* en;
};

