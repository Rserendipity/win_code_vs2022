class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        if (cost1 > cost2)
            swap(cost1, cost2);
        while (total >= 0) {
            ans += total / cost2 + 1;
            total -= cost1;
        }
        return ans;
    }
};