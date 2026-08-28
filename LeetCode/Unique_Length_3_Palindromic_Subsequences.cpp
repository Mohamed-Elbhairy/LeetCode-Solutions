/*
 * Problem Name: Unique Length 3 Palindromic Subsequences
 * Problem Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
 */

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> fst(26, -1), lst(26, -1);
        vector<vector<int>> pre(s.size(), vector<int>(26));
        for (int i = 0; i < s.size(); ++i) {
            if (fst[s[i] - 'a'] == -1)
                fst[s[i] - 'a'] = i;
            lst[s[i] - 'a'] = i;
        }
        int n = s.size();
        for (int i = 0; i < n; ++i) {

            pre[i][s[i] - 'a']++;
            if (i) {
                for (int j = 0; j < 26; ++j)
                    pre[i][j] += pre[i - 1][j];
            }
        }
        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            if (lst[i] == fst[i])
                continue;
            int cnt = 0;
            int r = lst[i] - 1;
            int l = fst[i];

            for (int j = 0; j < 26; ++j) {
                if (pre[r][j] - pre[l][j])
                    ++cnt;
            }
            ret += cnt;
        }
        return ret;
    }
};
