class Solution {
public:
  int minCount(vector<int> &coins) {
    int cnt = 0;
    for (auto &n : coins) {
      cnt += (n + 1) / 2;
    }
    return cnt;
  }
};