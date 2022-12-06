#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDifferentIntegers(string word)
    {
        string tmp;
        for (char ch : word)
        {
            if (isdigit(ch))
            {
                tmp += ch;
            }
            else
            {
                tmp += ' ';
            }
        }
        cout << tmp << endl;
        stringstream sin(tmp);
        unordered_set<string> hash;
        while (sin >> tmp)
        {
            auto it = tmp.begin();
            while (*it == '0' && it + 1 != tmp.end())
                ++it;
            string in(it, tmp.end());
            hash.insert(in);
        }
        return hash.size();
    }
};
int main()
{
    cout << Solution().numDifferentIntegers("ab123b00123");
    return 0;
}