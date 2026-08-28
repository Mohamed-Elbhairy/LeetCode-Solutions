/*
 * Problem Name: Longest Common Subsequence
 * Problem Link: https://leetcode.com/problems/longest-common-subsequence/
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        memset(dp, 0, sizeof dp);
        int n = text1.size();
        int m = text2.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (text1[i] == text2[j]) {
                    if (i > 0 and j > 0)
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = 1;
                } else {
                    if (i and j)
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    else if (i)
                        dp[i][j] = dp[i - 1][j];
                    else if (j)
                        dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
