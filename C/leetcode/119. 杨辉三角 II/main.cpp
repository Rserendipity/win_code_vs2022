class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        long long cur = 1;
        for (int i = 0; i <= rowIndex; i++) {
            res.push_back(cur);
            cur = cur*(rowIndex-i)/(i+1);
        }
        return res;
    }
};