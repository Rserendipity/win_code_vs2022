class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for(int i = 1; i <= num; i++){
            int sum = 0;
            int a = i;
            while(a > 0) {
                sum += a % 10;
                a /= 10;
            }
            if (sum % 2 == 0) {
                ans++;               
            }
        }
        return ans;
    }
};