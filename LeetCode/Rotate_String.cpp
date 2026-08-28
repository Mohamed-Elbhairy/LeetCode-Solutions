/*
 * Problem Name: Rotate String
 * Problem Link: https://leetcode.com/problems/rotate-string/
 */

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        string doubled = s + s;

        return doubled.find(goal) != string::npos;
    }
};
