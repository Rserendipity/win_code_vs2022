class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int tmp = start ^ goal;
        for (int i = 0; i < 32; i++) {
            if ((tmp>>i)&1)
                ans ++;
        }
        return ans;
    }
};