class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, pair<string, int>> hash;
        for (auto& s : words) {
            string t;
            for (int i = 1; i < s.size(); i++) {
                t += to_string(s[i - 1] - s[i]);
            }
            hash[t].first = s;
            hash[t].second += 1;
        }
        for (auto& [k,v] : hash) {
            if (v.second == 1) {
                return v.first;
            }
        }
        return "";
    }
};