/*
 * Problem Name: Add Binary
 * Problem Link: https://leetcode.com/problems/add-binary/
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        string ans = "";
        int i = a.length() - 1, j = b.length() - 1;

        while (i >= 0 || j >= 0 || c == 1) {
            int sum = c;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            c = sum / 2;
            ans = to_string(sum % 2) + ans;
        }

        return  ans;
    }
};

