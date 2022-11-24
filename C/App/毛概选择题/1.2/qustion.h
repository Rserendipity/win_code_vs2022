#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::fstream;

class qustion {

public:
	qustion();

	string GetOneQustion();

private:
	void GetOptions();
	int _current;

	vector<int> _randomOptions;
	vector<string> _qustions;
	vector<vector<string>> _options;

};