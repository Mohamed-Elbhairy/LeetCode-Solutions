/*
 * Problem Name: Number Of 1 Bits
 * Problem Link: https://leetcode.com/problems/number-of-1-bits/
 */

class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};
