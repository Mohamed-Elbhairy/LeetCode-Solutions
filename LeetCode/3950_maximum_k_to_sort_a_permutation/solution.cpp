/*
 * Problem Name: 3950. Maximum K To Sort A Permutation
 * Problem Link: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
 */

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i)
                k &= nums[i];
        }
        if (k == -1)
            k = 0;
        return k;
    }
};
