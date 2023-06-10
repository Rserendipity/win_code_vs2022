class Solution {
    int func(string& s) {
        int arr[26] = {0};
        for (auto& ch : s) {
            arr[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0)
                return arr[i];
        }
        return -1;
    }
    int search(int n, vector<int>& caculate) {
        int begin = 0, end = caculate.size() - 1, mid = 0;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (caculate[mid] < n) {
                begin = mid + 1;
            } else if (caculate[mid] > n) {
                end = mid - 1;
            } else {
                break;
            }
        }
        while (mid < caculate.size() && caculate[mid] <= n) {
            mid++;
        }
        return caculate.size() - mid;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> result;
        vector<int> caculate;
        for (auto& s : words) {
            caculate.push_back(func(s));
        }
        sort(caculate.begin(), caculate.end());
        for (auto& s : queries) {
            int n = func(s);
            result.push_back(search(n, caculate));
        }
        return result;
    }
};