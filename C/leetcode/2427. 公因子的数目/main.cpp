class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        int min = std::min(a,b);
        for (int i = 1; i <= min; i++) {
            if (a % i == 0 && b % i == 0)
                ans++;
        }
        return ans;
    }
};