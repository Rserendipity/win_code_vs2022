class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int sz = boxes.size();
        ans.resize(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (boxes[j] == '1') {
                    ans[i] += abs(i - j);
                }
            }
        }
        return ans;
    }
};