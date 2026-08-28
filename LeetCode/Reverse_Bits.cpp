/*
 * Problem Name: Reverse Bits
 * Problem Link: https://leetcode.com/problems/reverse-bits/
 */

class Solution {
public:
    int reverseBits(int n) {
        int ret = 0;
        for (int i = 0; i < 32; ++i)
            if (n & (1 << i))
                ret |= 1 << (32 - i - 1);
        return ret;
    }
};
