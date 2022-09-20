#define _CRT_SECURE_NO_WARNINGS 1
#include "MyString.h"
using namespace std;

void test1()
{
    MyString s1 = "abcd";
    MyString s2 = "abcd";
    MyString s3 = s1 + s2;

    s3 = s3 + "abcd";
    s3.ShowString();
    std::cout << s3 << std::endl;
    std::cout << s3[-1];
}

int main() 
{
    test1();
    return 0;
}
