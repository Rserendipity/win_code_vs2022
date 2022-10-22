#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int hash_chars[26] = { 0 };
        int hash_words[26] = { 0 };
        int count = 0;
        int flag = 0;
        for (auto& ch : chars) {
            hash_chars[ch - 'a']++;
        }
        for (auto& s : words) {
            flag = 0;
            memset(hash_words, 0, 26 * sizeof(int));

            for (auto& ch : s) {
                hash_words[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (hash_words[i] <= hash_chars[i]) {

                }
                else {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                count += s.size();
            }
        }
        return count;
    }
};
int main()
{
    vector<string> str = { "cat","bt","hat","tree" };
    Solution s;
    cout << s.countCharacters(str, "atach");

    return 0;
}
