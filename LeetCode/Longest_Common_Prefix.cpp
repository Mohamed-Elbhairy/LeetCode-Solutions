/*
 * Problem Name: Longest Common Prefix
 * Problem Link: https://leetcode.com/problems/longest-common-prefix/
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ret = "";
        int mn = 1e9;
        for (auto& i : strs)
            mn = min(int(i.size()), mn);
        for (int j = 0; j < mn; ++j) {
            char cur = strs[0][j];
            bool Ok = true;
            for (int i = 0; i < n; ++i) {
                if (strs[i][j] != cur) {
                    Ok = false;
                    break;
                }
                if (Ok == false)
                    break;
            }
            if (Ok)
                ret += cur;
            else
                break;
        }
        return ret ;
    }
};
