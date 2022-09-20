#include "MyString.h"

std::ostream& operator<<(std::ostream& out, MyString& str)
{
	out << str.s << std::endl;
	return out;
}


