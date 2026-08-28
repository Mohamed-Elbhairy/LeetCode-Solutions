/*
 * Problem Name: Last Stone Weight
 * Problem Link: https://leetcode.com/problems/last-stone-weight/
 */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while (pq.size() >= 2) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            y -= x;
            if (y > 0) {
                pq.push(y);
            }
        }
        if(pq.size())return pq.top();
        else return 0 ;
    }
};
