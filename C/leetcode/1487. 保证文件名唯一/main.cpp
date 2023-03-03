class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> hash;
        vector<string> ans;
        for (string& name : names) {
            if (hash.count(name) == 0) {
                hash[name] = 1;
                ans.push_back(name);
            } else {
                while (true) {
                    string newName = name + "(" + to_string(hash[name]) + ")";
                    hash[name]++;
                    if (hash.count(newName) == 0) {
                        hash[newName] = 1;
                        ans.push_back(newName);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};