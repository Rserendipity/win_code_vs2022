#pragma once
#include <iostream>
class Link
{
public:
	Link();
	Link(int x);
	Link(const Link& s);
	void Add(int num);
	void Reverse();
	void Pop();
	int GetHeadVal();
	int GetSize();
	~Link();
private:
	int size;
	int val;
	Link* head;
};
