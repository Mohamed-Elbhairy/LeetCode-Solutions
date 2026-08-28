/*
 * Problem Name: Minimum One Bit Operations To Make Integers Zero
 * Problem Link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
 */

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        while (n) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};
