/*
 * Problem Name: 0022. Generate Parentheses
 * Problem Link: https://leetcode.com/problems/generate-parentheses/
 */

class Solution {
    vector<string> ret;
    void rec(int n, int cnt, string& s) {
        if (s.size() == n) {
            if (cnt == 0)
                ret.push_back(s);
            return;
        }
        s += '(';
        rec(n, cnt + 1, s);
        s.pop_back();
        if (cnt) {
            s += ')';
            rec(n, cnt - 1, s);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        ret.clear();
        string s = "";
        rec(2*n, 0, s);
        return ret;
    }
};
