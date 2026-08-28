/*
 * Problem Name: Maximum Number Of Jumps To Reach The Last Index
 * Problem Link: https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
 */

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        dp[0] = 0;      
        for (int i = 0; i < n; ++i) {
            if(dp[i] == -1)continue;
            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) <= target)
                    dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};
