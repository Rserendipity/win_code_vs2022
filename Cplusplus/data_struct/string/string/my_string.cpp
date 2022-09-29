#define _CRT_SECURE_NO_WARNINGS 1
#include "my_string.h"

String::String()
{
	this->str = nullptr;
	this->size = 0;
}

String::String(const char* s)
{
	this->size = strlen(s);
	this->str = new char[size + 1];
	strcpy(this->str, s);
}

String::String(const String& s)
{
	this->size = s.size;
	this->str = new char[size + 1];
	strcpy(this->str, s.str);
}

String::~String()
{
	this->size = 0;
	delete[] this->str;
}

const String String::operator+(String& s)
{
	String temp;
	temp.size = this->size + s.size;
	temp.str = new char[temp.size + 1];
	strcpy(temp.str, this->str);
	strcat(temp.str, s.str);
	return temp;
}

String& String::operator+=(String& s)
{
	this->size += s.size;
	char* temp = this->str;
	this->str = new char[this->size + 1];
	strcpy(this->str, temp);
	strcat(this->str, s.str);
	delete[] temp;
	return *this;
}

String& String::operator=(String& s)
{
	if (this->str != NULL)
	{
		delete[] this->str;
	}
	this->str = new char[s.size + 1];
	this->size = s.size;
	strcpy(this->str, s.str);
	return *this;
}

char& String::operator[](int index)
{
	if (index >= 0 && index <= this->size)
	{
		return this->str[index];
	}
	else
	{
		return this->str[0];
	}
}

std::ostream& operator<<(std::ostream& out, String& s)
{
	out << s.str << std::endl;
	return out;
}
