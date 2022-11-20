#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

namespace cjj {
	// 使用 STL 容器来存储单词
	using std::vector;
	using std::string;
	using std::queue;

	class Word
	{
	public:
		const int MAX_WORD_SIZE = 4449;				  // 总共的单词数量
		const char Options[4] = { 'A','B','C','D' };  // 选项数组

		Word();

	private:
		int _todayTarget;              // 今日目标
		int _currentProgess;           // 总进度

		std::fstream _fstream;         // 文件流，读取中英文
		bool _isPause;                 // 背完当前以后是否暂停标志

		vector<int> _randArray;        // 获取随机数作为选项

		vector<queue<string>> _enToCh; // 英选中
		vector<queue<string>> _chToEn; // 中选英
		queue<string> _errWords;       // 保存错误，准备复习

	};
}


