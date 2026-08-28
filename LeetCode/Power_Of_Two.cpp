/*
 * Problem Name: Power Of Two
 * Problem Link: https://leetcode.com/problems/power-of-two/
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n == 0? false :!(n&(n-1LL));
    }
};
