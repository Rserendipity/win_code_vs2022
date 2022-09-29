#pragma once
#include <iostream>
#include <cstring>
class String
{
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();

	friend std::ostream& operator<<(std::ostream& out, String& s);

	const String operator+(String& s);
	String& operator+=(String& s);
	String& operator=(String& s);
	char& operator[](int index);

private:
	char* str;
	int size;
};

