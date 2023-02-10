class Solution {
public:
    int minPartitions(string n) {
        int max = 0;
        for (char ch : n) {
            max = std::max(ch - '0', max);
        }
        return max;
    }
};