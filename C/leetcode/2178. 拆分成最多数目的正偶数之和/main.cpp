class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1) {
            return {};
        } else {
            vector<long long> result;
            long long sub = 2;
            for (long long i = 2; finalSum - i >= 0 && finalSum - i * 2 - 2 >= 0; i += 2) {
                result.push_back(i);
                finalSum -= i;
            }
            result.push_back(finalSum);
            return result;
        }
    }
};