class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int rule = 0, cnt = 0;
        if (ruleKey == "color") {
            rule = 1;
        } else if (ruleKey == "name") {
            rule = 2;
        }
        for (auto& vv : items) {
            if (vv[rule] == ruleValue) {
                cnt ++;
            }
        }
        return cnt;
    }
};