class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        string tmp("//");
        for (auto& s : folder) {
            if (s.compare(0, tmp.size(), tmp) != 0) {
                ans.push_back(s);
                tmp = s + '/';
            }
        }
        return ans;
    }
};