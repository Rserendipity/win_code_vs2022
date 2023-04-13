class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int n : nums) {
            if (n%2 == 0)
                hash[n]++;
        }
        int m_k = -1, m_v = -1;
        for (auto& [k,v] : hash) {
            if (v > m_v) {
                m_v = v;
                m_k = k;
            }
            if (v == m_v && k < m_k)
                m_k = k;
        }
        return m_k;
    }
};