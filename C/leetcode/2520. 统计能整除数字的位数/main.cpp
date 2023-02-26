class Solution {
public:
    int countDigits(int num) {
        int arr[10] = {0};
        int n = num;
        int index = 0;
        while(n) {
            arr[index++] = n % 10;
            n /= 10;
        }
        int ans = 0;
        for (int i = 0 ; i < index; i++) {
            if (num % arr[i] == 0)
                ans++;
        }
        return ans;
    }
};