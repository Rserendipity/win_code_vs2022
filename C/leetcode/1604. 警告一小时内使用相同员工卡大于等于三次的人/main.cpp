class Solution {
    bool isOverTime(vector<int>& v) {
        sort(v.begin(), v.end());
        for (int i = 2; i < v.size(); i++) {
            if (v[i] - v[i - 2] <= 60) {
                return true;
            }
        }
        return false;
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> hash;
        vector<string> ans;
        for (int i = 0; i < keyName.size(); i++) {
            int hour = (keyTime[i][0] - '0') * 10 + (keyTime[i][1] - '0');
            int minute = (keyTime[i][3] - '0') * 10 + (keyTime[i][4] - '0');
            hash[keyName[i]].push_back(hour * 60 + minute);
        }
        for (auto& kv : hash) {
            if (isOverTime(kv.second))
                ans.push_back(kv.first);
        }
        return ans;
    }
};