class Solution {
    inline int mod(int n) {
        return n % 3 == 0 || n % 5 == 0 || n % 7 == 0;
    }
public:
    int sumOfMultiples(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (mod(i))
                ans += i;
        return ans;
    }
};