class Solution {
public:
    int alternateDigitSum(int n) {
        int arr[10] = {0};
        int index = 0;
        while (n) {
            arr[index++] = n % 10;
            n /= 10;
        }
        int flag = index % 2 ? 1 : -1;
        int sum = 0;
        for (int i = 0; i < index; i++) {
            sum += flag * arr[i];
            flag *= -1;
        }
        return sum;
    }
};