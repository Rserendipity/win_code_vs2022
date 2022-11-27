#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
    const string map[11] = { "", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    void dfs(vector<string>& ans, int index, string& digits, string path) {
        if (index == digits.size())
        {
            ans.push_back(path);
            return;
        }
        int n = digits[index] - '0';
        for (int i = 0; i < map[n].size(); i++) {
            path.push_back(map[n][i]);
            dfs(ans, index + 1, digits, path);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int index = 0;
        vector<string> ans;
        dfs(ans, index, digits, "");
        return ans;
    }
};
int main()
{
    Solution a; 
    a.letterCombinations("23");
    return 0;
}
