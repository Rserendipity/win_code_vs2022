class Solution {
    bool isnum(string& s) {
        for (char ch : s) {
            if (!(ch >= '0' && ch <= '9'))
                return false;
        }
        return true;
    }
public:
    int maximumValue(vector<string>& strs) {
        int mx = -1;
        for (auto& s : strs) {
            if (isnum(s)) {
                mx = std::max(stoi(s), mx);
            } else {
                mx = std::max((int)s.size(), mx);
            }
        }
        return mx;
    }
};