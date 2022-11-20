#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char buf[10000];
    fstream fi;
    fstream fo1;
    fstream fo2;
    string ch;
    int count = 0;
    fi.open("./1.txt", ios::in);
    fo1.open("./ans.txt", ios::out);
    fo2.open("./out.txt", ios::out);
    string tmp;
    while (!fi.eof())
    {
        fi.getline(buf, 10000);
        tmp = buf;
        auto it = find(tmp.begin(), tmp.end(), '(');
        if (it != tmp.end()) 
        {
            ++it;
            while (*it != ')')
            {
                ch += *it;
                *it = ' ';
                ++it;
            }
            count++;
            fo1 << count << "£º" << ch << "\n";
        }
        fo2 << tmp << "\n";
        ch.clear();
        tmp.clear();
    }


    return 0;
}
