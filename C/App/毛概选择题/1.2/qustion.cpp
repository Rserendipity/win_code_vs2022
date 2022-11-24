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
		vv.resize(233); // ��ѡ��������Ŀ����
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
		_randomOptions[i] = -1; // �ȸ���-1�������ظ�
	}
	i = 0;
	while (i < 4)
	{
		int temp = rand() % 4; // ��ȡһ���������ģ4 ---> 0 ~ 3 ��Ӧ�±�
		if (_randomOptions[0] != temp 
			&& _randomOptions[1] != temp 
			&& _randomOptions[2] != temp 
			&& _randomOptions[3] != temp)
		{
			// ��ȡ�������ֵ�����������ֵ����ͬ��ʱ������鸳ֵ��Ȼ�� i++
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
