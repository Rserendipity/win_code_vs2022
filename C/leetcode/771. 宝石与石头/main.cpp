class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> hash;
        for (auto& ch : jewels) {
            hash.insert(ch);
        }
        int cnt = 0;
        for (auto& ch : stones) {
            if (hash.count(ch) != 0) {
                cnt ++;
            }
        }
        return cnt;
    }
};