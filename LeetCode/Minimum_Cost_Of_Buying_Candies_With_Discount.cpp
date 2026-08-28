/*
 * Problem Name: Minimum Cost Of Buying Candies With Discount
 * Problem Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
 */

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // 2 2 5 6 7 9 => 7 + 16 = 23
        int ret = 0;
        sort(cost.begin(), cost.end());
        for (int i = cost.size() - 1; i >= 0;) {
            ret += cost[i];
            if (i - 1 >= 0)
                ret += cost[i - 1];
            i -= 3;
        }
        return ret;
    }
};
