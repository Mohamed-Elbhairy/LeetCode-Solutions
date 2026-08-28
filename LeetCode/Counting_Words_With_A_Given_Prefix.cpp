/*
 * Problem Name: Counting Words With A Given Prefix
 * Problem Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/
 */

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (auto &s : words) {
            bool ok = 1;
            for (int i = 0; i < pref.size(); ++i) {
                if (s[i] != pref[i]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};
