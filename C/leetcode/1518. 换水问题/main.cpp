class Solution {
    int div = 1;
    int _numWaterBottles(int money, int bottle) {
        if (money == 0 && bottle < div)
            return 0;
        money += bottle / div;
        bottle %= div;
        return money + _numWaterBottles(0, money + bottle);
    }
public:
    int numWaterBottles(int numBottles, int numExchange) {
        div = numExchange;
        return _numWaterBottles(numBottles, 0);
    }
};