/*
 * Problem Name: 4084. Maximize Sum Of Squares Of Digits
 * Problem Link: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
 */

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ret = "";
        while (ret.size() < num) {
            int x = min(9, sum);
            ret += char('0' + x);
            sum -= x;
        }
        if(sum)return "";
        return ret;
    }
};
