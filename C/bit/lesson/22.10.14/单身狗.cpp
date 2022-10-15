#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    map<int, int> hash;

    vector<int> nums = { 1,2,3,4,5,1,2,3,4,6 };

    for (auto& n : nums) {
        hash[n]++;
    }

    vector<int> ret;

    for (auto& kv : hash) {
        if (kv.second == 1) {
            ret.push_back(kv.first);
        }
    }

    for (auto& n : ret) {
        cout << n << " ";
    }

    return 0;
}
