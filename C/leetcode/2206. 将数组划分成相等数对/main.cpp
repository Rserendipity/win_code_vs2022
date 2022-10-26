#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> hash;
        for (auto& n : nums) {
            hash[n]++;
        }
        for (auto& kv : hash) {
            if (kv.second % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}
