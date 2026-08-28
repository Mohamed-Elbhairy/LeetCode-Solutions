/*
 * Problem Name: Number Of Strings That Appear As Substrings In Word
 * Problem Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
 */

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (string &s : patterns) {
            if (word.find(s) != string::npos)
                ans++;
        }

        return ans;
    }
};
