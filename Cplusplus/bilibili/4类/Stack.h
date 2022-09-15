#pragma once
#include <iostream>
#include <cstring>
#include "Link.h"
class Stack
{
public:
	Stack();
	Stack(int arr[], int size);
	Stack(const Stack&);
	~Stack();
	void Push(int val);
	void Pop();
	int GetTop();
	int GetValSize();
private:
	Link l;
};

