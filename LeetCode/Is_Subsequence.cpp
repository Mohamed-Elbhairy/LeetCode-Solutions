/*
 * Problem Name: Is Subsequence
 * Problem Link: https://leetcode.com/problems/is-subsequence/
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        if(s == t)return true;
        for (int i = 0; i < t.size(); ++i) {
            if(s[idx] == t[i])++idx;
            if(idx == s.size())return true;
        }
        return false;
    }
};
