#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

namespace cjj {
	// ʹ�� STL �������洢����
	using std::vector;
	using std::string;
	using std::queue;

	class Word
	{
	public:
		const int MAX_WORD_SIZE = 4449;				  // �ܹ��ĵ�������
		const char Options[4] = { 'A','B','C','D' };  // ѡ������

		Word();

	private:
		int _todayTarget;              // ����Ŀ��
		int _currentProgess;           // �ܽ���

		std::fstream _fstream;         // �ļ�������ȡ��Ӣ��
		bool _isPause;                 // ���굱ǰ�Ժ��Ƿ���ͣ��־

		vector<int> _randArray;        // ��ȡ�������Ϊѡ��

		vector<queue<string>> _enToCh; // Ӣѡ��
		vector<queue<string>> _chToEn; // ��ѡӢ
		queue<string> _errWords;       // �������׼����ϰ

	};
}


