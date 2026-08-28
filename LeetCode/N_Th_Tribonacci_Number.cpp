/*
 * Problem Name: N Th Tribonacci Number
 * Problem Link: https://leetcode.com/problems/n-th-tribonacci-number/
 */

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i%3] = dp[(i - 1)%3] + dp[(i - 2)%3] + dp[(i - 3)%3];
        }
        return dp[n%3];
    }
};
