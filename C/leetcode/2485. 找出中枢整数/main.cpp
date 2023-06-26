class Solution {
public:
    int pivotInteger(int n) {
        int sum = (1+n)*n/2;
        double result = sqrt(sum);
        if ((double)(int)result == result) {
            return (int)result;
        } else {
            return -1;
        }
    }
};