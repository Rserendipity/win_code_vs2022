#define _CRT_SECURE_NO_WARNINGS 1
#include <map>
#include <iostream>
using namespace std;
int main() 
{
    map<int, int> mymap;
    mymap[10] = 1000;
    auto a = mymap.find(10);
    if (a != mymap.end())
    {
        cout << a->second << endl;
    }
    return 0;
}
