/*
 * Problem Name: The Two Sneaky Numbers Of Digitville
 * Problem Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
 */

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 3, 0);
        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
        }
        vector<int> ret;
        for (int i = 0; i <= n + 2; ++i) {
            while (freq[i] > 1)
                ret.push_back(i), freq[i]--;
        }
        return ret ;
    }
};
