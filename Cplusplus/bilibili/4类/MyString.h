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
		char* temp = s;        // ����һ��s��ǰ�ĵ�ַ
		s = new char[len + 1]; // ��s�����µĿռ�
		strcpy(s, temp);
		strcat(s, str.s);

		// �������ͷ�tempָ��Ŀռ�
		delete[] temp;

		return *this;
	}
	MyString& operator+(const char* str)
	{
		this->len += strlen(str);  // 
		char* temp = s;        // ����һ��s��ǰ�ĵ�ַ
		s = new char[len + 1]; // ��s�����µĿռ�
		strcpy(s, temp);
		strcat(s, str);

		// �������ͷ�tempָ��Ŀռ�
		delete[] temp;

		return *this;
	}
	char operator[] (int pos)
	{
		if (pos > this->len || pos < 0)
		{
			std::cout << "����������Χ" << std::endl;
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

