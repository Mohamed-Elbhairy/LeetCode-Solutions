/*
 * Problem Name: Ones And Zeroes
 * Problem Link: https://leetcode.com/problems/ones-and-zeroes/
 */

class Solution {
public:
    int dp[2][111][111];
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> v(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            for (auto c : strs[i]) {
                if (c == '0')
                    v[i].first++;
                else
                    v[i].second++;
            }
        }
        for (int i = strs.size() - 1; i >= 0; --i) {
            for (int c1 = m; c1 >= 0; c1--) {
                for (int c2 = n; c2 >= 0; --c2) {
                    dp[i & 1][c1][c2] = dp[(i + 1) & 1][c1][c2];
                    int nc1 = c1 + v[i].first;
                    int nc2 = c2 + v[i].second;
                    if (nc1 <= m && nc2 <= n) {
                        dp[i & 1][c1][c2] = max(dp[(i + 1) & 1][nc1][nc2] + 1,
                                                dp[i & 1][c1][c2]);
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};
