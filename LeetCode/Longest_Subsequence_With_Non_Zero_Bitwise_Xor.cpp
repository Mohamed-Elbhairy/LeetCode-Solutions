/*
 * Problem Name: Longest Subsequence With Non Zero Bitwise Xor
 * Problem Link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
 */

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        auto tot = 0, nonZero = 0;

        for (auto& n : nums) {
            nonZero |= n > 0;
            tot ^= n;
        }

        return nonZero * (nums.size() - !tot);
    }
};
