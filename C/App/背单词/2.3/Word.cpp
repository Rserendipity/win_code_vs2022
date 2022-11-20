#include "Word.h"


cjj::Word::Word()
{
	_fstream.open("./data/info.txt", std::ios::in);
	_fstream >> _currentProgess >> _todayTarget >> _isPause;
	_fstream.close();

	_enToCh.resize(4);
	_chToEn.resize(4);

	for (int i = 0; i < 4; i++) 
	{
		string path;
		path += "./data/ch";
		path += std::to_string(i);
		path += ".txt";

		_fstream.open(path, std::ios::in);

		// 跳过 _currentProgess 行
		for (int i = 0; i < _currentProgess; i++)
		{
			char ch = 0;
			while (ch != '\n')
				ch = _fstream.get();
		}

		// 读取今日的单词数据到 _enToCh 中
		for (int i = 0; i < _todayTarget; i++) 
		{
			char tmp[256];
			_fstream.getline(tmp, 255);
			_enToCh[i].push(tmp);
		}

	}

	
}
