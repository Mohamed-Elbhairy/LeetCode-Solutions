/*
 * Problem Name: 1737. Maximum Nesting Depth Of The Parentheses
 * Problem Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 */

class Solution {
    public: 
    int maxDepth(string s) {
        int depth = 0;
        int r = 0;
        for (char c : s) {
            if (c == ')') {
                depth--;
                continue;
            }
            // Digits and operators
            if (c != '(') continue;
            depth++;
            // New max only possible after '('
            if (depth > r) r = depth;
        }
        return r;
    }
};
