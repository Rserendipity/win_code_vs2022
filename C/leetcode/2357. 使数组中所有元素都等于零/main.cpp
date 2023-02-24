class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> hash;
        for (int n : nums) {
            if (n != 0)
                hash.insert(n);
        }
        return hash.size();
    }
};