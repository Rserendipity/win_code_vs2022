#include "qustion.h"

qustion::qustion()
{
	_current = 0;
	fstream fin("./data/single/qustion.txt", std::ios::in);
	char* tmp = new char[2000];
	srand((unsigned int)(void*)tmp);

	while (!fin.eof())
	{
		fin.getline(tmp, 2000);
		_qustions.push_back(tmp);
	}
	fin.close();

	_options.resize(4);

	fstream fyes("./data/single/yes.txt", std::ios::in);
	fstream fno("./data/single/no.txt", std::ios::in);

	for (auto& vv : _options)
	{
		vv.resize(233); // 单选题的最大题目数量
	}

	for (auto& s : _options[0])
	{
		fyes.getline(tmp, 2000);
		s = tmp;
	}

	for (int j = 0; j < 233; j++)
	{
		for (int i = 1; i < 4; i++)
		{
			fno.getline(tmp, 2000);
			_options[i][j] = tmp;
		}
		fno.getline(tmp, 2000);
	}

	delete[] tmp;
}

void qustion::GetOptions()
{
	_randomOptions.resize(4);
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		_randomOptions[i] = -1; // 先给上-1，以免重复
	}
	i = 0;
	while (i < 4)
	{
		int temp = rand() % 4; // 获取一个随机数，模4 ---> 0 ~ 3 对应下标
		if (_randomOptions[0] != temp 
			&& _randomOptions[1] != temp 
			&& _randomOptions[2] != temp 
			&& _randomOptions[3] != temp)
		{
			// 获取到的随机值和数组的其他值都不同的时候给数组赋值，然后 i++
			_randomOptions[i] = temp;
			i++;
		}
	}
}

string qustion::GetOneQustion()
{
	GetOptions();
	string out;
	out += _qustions[_current];
	out += "\n";
	for (int i = 0; i < 4; i++)
	{
		out += 'A' + i;
		out += _options[_randomOptions[i]][_current];
		out += "\n";
	}
	_current++;
	return out;
}
