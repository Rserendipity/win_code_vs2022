#include "Word.h"
int Word::current = 0;

Word::Word()
{
	ifstream fin;
	char* temp = new char[MAX_WORD_SIZE];
	for (int i = 0; i < 4; i++)
	{
		ch[i] = new string[MAX_WORD_SIZE];
		string s;
		s += "./data/ch";
		s += to_string(i);
		s += ".txt";
		cout << s << endl;
		fin.open(s, ios::in);
		for (int j = 0; j < MAX_WORD_SIZE; j++)
		{
			fin.getline(temp, MAX_WORD_SIZE);
			ch[i][j] += temp;
		}
	}
	delete temp;
}

string** Word::GetCh()
{
	return this->ch;
}

Word::~Word()
{
	for (int i = 0; i < 4; i++)
	{
		delete[] ch[i];
	}
}
