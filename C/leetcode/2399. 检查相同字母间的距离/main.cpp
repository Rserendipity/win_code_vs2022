#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool checkDistances(string s, const vector<int>& distance) {
        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); i++) {
            if (hash.insert(make_pair(s[i], i)).second == false) {
                if (distance[s[i] - 'a'] != i - hash[s[i]] - 1) {
                    cout << i << endl;
                    cout << hash[i] << endl;
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution().checkDistances("abaccb", { 1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 });
    return 0;
}
