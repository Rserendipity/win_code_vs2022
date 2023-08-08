class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> v;
        while (n) {
            v.push_back(n%10);
            n /= 10;
        }
        int sum = 0, mul = 1;
        for (auto& n : v) {
            sum += n;
            mul *= n;
        }
        return mul - sum;
    }
};