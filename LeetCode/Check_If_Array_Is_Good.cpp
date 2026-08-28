/*
 * Problem Name: Check If Array Is Good
 * Problem Link: https://leetcode.com/problems/check-if-array-is-good/
 */

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int freq[201] = {};
        for (int i : nums) {
            freq[i]++;
        }
        int n = nums.size() - 1;
        for (int i = 1; i < n; ++i) {
            if (freq[i] != 1)
                return false;
        }
        return freq[n] == 2;
    }
};
