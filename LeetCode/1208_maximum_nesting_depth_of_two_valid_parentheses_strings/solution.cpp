/*
 * Problem Name: 1208. Maximum Nesting Depth Of Two Valid Parentheses Strings
 * Problem Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
 */

class Solution {
public:
    vector<int> maxDepthAfterSplit(auto s) {
        int n = s.size(); vector<int> res(n);
        
        for (int i = 0; i < n; i++)
            res[i] = (i ^ s[i]) & 1;

        return res;
    }
};
