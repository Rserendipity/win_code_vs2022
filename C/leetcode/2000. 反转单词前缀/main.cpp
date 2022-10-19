#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto pos = word.find(ch);
        if (pos == word.npos) {
            return word;
        }
        else {
            int head = 0;
            while (head < pos) {
                swap(word[head], word[pos]);
                head++;
                pos--;
            }
            return word;
        }
    }
};
int main() 
{
    string s = "abcdefg";
    Solution ans;
    cout << ans.reversePrefix(s, 'e') << endl;
    return 0;
}
