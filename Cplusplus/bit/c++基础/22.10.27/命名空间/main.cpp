#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 10;
    const auto y = x;

    cout << typeid(y).name() << endl;
    return 0;
}
