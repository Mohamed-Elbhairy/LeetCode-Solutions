/*
 * Problem Name: 0020. Valid Parentheses
 * Problem Link: https://leetcode.com/problems/valid-parentheses/
 */

class Solution {
    bool isOpen(char c) { return c == '(' || c == '{' || c == '['; }
    char rev(char c) {
        if (c == ')')
            return '(';
        else if (c == ']')
            return '[';
        else
            return '{';
    }

public:
    bool isValid(string s) {
        stack<char> st;
        for (auto& c : s) {
            if (isOpen(c))
                st.push(c);
            else {
                if (st.empty() || st.top() != rev(c))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
