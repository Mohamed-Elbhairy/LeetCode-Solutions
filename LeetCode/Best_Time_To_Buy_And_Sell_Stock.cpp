/*
 * Problem Name: Best Time To Buy And Sell Stock
 * Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suff(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            suff[i] = max(suff[i + 1], prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, suff[i + 1] - prices[i]);
        }
        return ans ; 
    }
};
