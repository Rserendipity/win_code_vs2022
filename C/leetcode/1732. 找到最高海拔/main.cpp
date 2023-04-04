class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0, now = 0;
        for (int n : gain) {
            max = std::max(max, now + n);
            now += n;
        }
        return max;
    }
};