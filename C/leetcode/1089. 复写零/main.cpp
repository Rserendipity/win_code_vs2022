class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for (auto& num : arr) {
            if (num == 0)
                cnt++;
        }
        arr.resize(n + cnt);
        int i = n - 1, j = n + cnt - 1;
        while (i >= 0) {
            if (arr[i] != 0)
                arr[j--] = arr[i--];
            else {
                arr[j--] = 0;
                arr[j--] = arr[i--];
            }
        }
        arr.resize(n);
    }
};