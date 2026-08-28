/*
 * Problem Name: Find The Length Of The Longest Common Prefix
 * Problem Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
 */

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, bool> freq;
        for (int i : arr1) {
            string s = to_string(i);
            string t = "";
            for (auto j : s) {
                t += j;
                freq[t] = 1;
            }
        }
        int ret = 0;
        for (int i : arr2) {
            string s = to_string(i);
            string t = "";
            for (auto j : s) {
                t += j;
                if (freq[t] && ret < t.size()) {
                    ret = t.size();
                }
            }
        }
        return ret;
    }
};
