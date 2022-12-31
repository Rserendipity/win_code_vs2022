class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int sz = seats.size();
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};