#define _CRT_SECURE_NO_WARNINGS 1
#include "my_string.h"

int main() 
{
    using namespace std;
    String s1("s1");
    String s2("s2");
    cout << s1 << endl;
    cout << s2 << endl;
    s2 += s1;
    cout << s2 << endl;
    String s3 = s1 + s2;
    s3 = s1;
    cout << s3 << endl;
    cout << s3[5] << endl;
    return 0;
}
