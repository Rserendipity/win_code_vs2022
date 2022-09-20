#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
class MyArr
{
public:
	MyArr();
	MyArr(int arr[], int size);
	MyArr(const MyArr& arr);
	~MyArr();

	void PushByPos(int val, int pos);
	void PushByHead(int val);
	void PushByTail(int val);
	void PopByPos(int pos);
	void PopByHead();
	void PopByTail();
	void ShowAllVal();


	int GetValByPos(int pos);
	int GetValByHead();
	int GetValByTail();
	int GetSize();

private:
	int* arr;
	int cap;
	int size;
};

