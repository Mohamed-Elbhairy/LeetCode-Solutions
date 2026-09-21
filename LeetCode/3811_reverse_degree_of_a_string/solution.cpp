/*
 * Problem Name: 3811. Reverse Degree Of A String
 * Problem Link: https://leetcode.com/problems/reverse-degree-of-a-string/
 */

class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans += ('z' - s[i] + 1) * (i + 1);
        }
        return ans;
    }
};
