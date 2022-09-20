#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <cstring>
class MyString {
	friend std::ostream& operator<<(std::ostream& out, MyString& str);
public:
	MyString()
	{
		s = NULL;
		len = 0;
	}
	MyString(const char* str)
	{
		len = strlen(str);
		s = new char[len + 1];
		strcpy(s, str);
	}
	MyString(const MyString& str)
	{
		len = str.len;
		s = new char[len + 1];
		strcpy(s, str.s);
	}
	~MyString()
	{
		this->len = 0;
		delete[] this->s;
	}
	
	MyString& operator+(MyString& str)
	{
		this->len += str.len;  // 
		char* temp = s;        // 保存一下s当前的地址
		s = new char[len + 1]; // 给s开辟新的空间
		strcpy(s, temp);
		strcat(s, str.s);

		// 结束后释放temp指向的空间
		delete[] temp;

		return *this;
	}
	MyString& operator+(const char* str)
	{
		this->len += strlen(str);  // 
		char* temp = s;        // 保存一下s当前的地址
		s = new char[len + 1]; // 给s开辟新的空间
		strcpy(s, temp);
		strcat(s, str);

		// 结束后释放temp指向的空间
		delete[] temp;

		return *this;
	}
	char operator[] (int pos)
	{
		if (pos > this->len || pos < 0)
		{
			std::cout << "超出索引范围" << std::endl;
			return -1;
		}
		return *(this->s + pos);
	}

	void ShowString()
	{
		std::cout << s << std::endl;
	}
	int GetSize()
	{
		return this->len;
	}
private:
	char* s;
	int len;
};

