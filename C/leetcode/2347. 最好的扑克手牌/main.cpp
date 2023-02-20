class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (suits[0] == suits[1] 
        && suits[1] == suits[2] 
        && suits[2] == suits[3] 
        && suits[3] == suits[4] ) {
            return "Flush";
        }
        int arr[14] = {0};
        bool three = false;
        bool pair = false;
        for (int n : ranks) {
            arr[n]++;
            if (arr[n] >= 2) {
                pair = true;
            }
            if (arr[n] >= 3) {
                three = true;
            }
        }
        if (three) {
            return "Three of a Kind";
        }
        if (pair) {
            return  "Pair";
        }
        return "High Card";
    }
};