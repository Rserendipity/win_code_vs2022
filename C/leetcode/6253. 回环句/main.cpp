#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        stringstream sin(sentence);
        string str;
        vector<string> v;
        while (sin >> str)
        {
            v.push_back(str);
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].back() != v[(i + 1) % v.size()].front())
                return false;
        }
        return true;
    }
};
int main()
{

    return 0;
}
