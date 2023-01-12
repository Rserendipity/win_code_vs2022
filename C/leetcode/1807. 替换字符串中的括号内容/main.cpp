class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        unordered_map<string, string> hash;
        for (auto& vs : knowledge) {
            hash[vs[0]] = vs[1];
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(') {
                ans += s[i];
            } else {
                int pos = i;
                while (s[pos] != ')')
                    ++pos;
                string tmp(s.begin() + i + 1, s.begin() + pos);
                if (hash.find(tmp) == hash.end())
                    ans += '?';
                else 
                    ans += hash[tmp];
                i += pos - i;
            }
        }
        return ans;
    }
};