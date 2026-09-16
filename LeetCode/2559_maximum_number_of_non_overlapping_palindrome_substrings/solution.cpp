/*
 * Problem Name: 2559. Maximum Number Of Non Overlapping Palindrome Substrings
 * Problem Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
 */

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> is_pal(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                is_pal[i][j] = (s[i] == s[j]) && is_pal[i + 1][j - 1];
            }
        }
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (int j = 0; j <= i - k; ++j) {
                if (is_pal[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};
