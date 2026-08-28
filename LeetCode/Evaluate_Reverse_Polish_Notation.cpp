/*
 * Problem Name: Evaluate Reverse Polish Notation
 * Problem Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 */

class Solution {
public:
    int calc(int a, int b, string c) {
        if (c == "+")
            return a + b;
        else if (c == "-")
            return a - b;
        else if (c == "*")
            return a * b;
        else
            return a / b;
    }
    int evalRPN(vector<string>& tokens) {
        string operators = "/+-*";
        stack<int> st;
        int ans = -1;
        for (int i = 0; i < tokens.size(); ++i) {
            if (operators.find(tokens[i]) != string::npos) {
                int b = (st.top());
                st.pop();
                int a = (st.top());
                st.pop();
                st.push(calc(a, b,tokens[i]));
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
