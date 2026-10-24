class Solution {
private:
    int dateToDays(string s) {
        int month = (s[0] - '0') * 10 + (s[1] - '0');
        int day = (s[3] - '0') * 10 + (s[4] - '0');
        int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int totalDays = day;
        for (int i = 1; i < month; ++i) {
            totalDays += monthDays[i];
        }
        return totalDays;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int aliceArrival = dateToDays(arriveAlice);
        int aliceLeave = dateToDays(leaveAlice);
        int bobArrival = dateToDays(arriveBob);
        int bobLeave = dateToDays(leaveBob);

        int L = max(aliceArrival, bobArrival);
        int R = min(aliceLeave, bobLeave);

        return max(0, R - L + 1);
    }
};
