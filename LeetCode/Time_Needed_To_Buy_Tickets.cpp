/*
 * Problem Name: Time Needed To Buy Tickets
 * Problem Link: https://leetcode.com/problems/time-needed-to-buy-tickets/
 */

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for (int i = 0; i < tickets.size(); ++i) {
            q.push(i);
        }
        int ans = 0;
        while (q.size() && tickets[k]) {
            ++ans;
            int idx = q.front();
            q.pop();
            if (--tickets[idx])
                q.push(idx);
        }
        return ans;
    }
};
