class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int month[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int day[366] = {0};
        int begin = month[(arriveAlice[0]-'0')*10+arriveAlice[1]-'0']+(arriveAlice[3]-'0')*10+arriveAlice[4]-'0';
        int end = month[(leaveAlice[0]-'0')*10+leaveAlice[1]-'0']+(leaveAlice[3]-'0')*10+leaveAlice[4]-'0';
        for (int i = begin; i <= end; i++) {
            day[i]++;
        }

        begin = month[(arriveBob[0]-'0')*10+arriveBob[1]-'0']+(arriveBob[3]-'0')*10+arriveBob[4]-'0';
        end = month[(leaveBob[0]-'0')*10+leaveBob[1]-'0']+(leaveBob[3]-'0')*10+leaveBob[4]-'0';
        

        for (int i = begin; i <= end; i++) {
            day[i]++;
        }

        int ans = 0;
        for (int i = 0; i < 366; i++) {
            if (day[i] == 2)
                ans++;
        }

        return ans;
    }
};