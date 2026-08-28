/*
 * Problem Name: Smallest Palindromic Rearrangement I
 * Problem Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 */

class Solution {
public:
    string smallestPalindrome(string s) {
        string ret = "";
        int freq[26] = {};
        for (auto i : s)
            freq[i - 'a']++;
        char mid = '#';
        for (int i = 0; i < 26; ++i) {
            if (freq[i] & 1)
                mid = char(i + 'a');
            int cnt = 0;
            while (cnt < freq[i] / 2) {
                ret += char(i + 'a');
                ++cnt;
            }
        }
        if (mid != '#')
            ret += mid;
        for (int i = 25; i >= 0; --i) {

            int cnt = 0;
            while (cnt < freq[i] / 2) {
                ret += char(i + 'a');
                ++cnt;
            }
        }
        return ret;
    }
};
