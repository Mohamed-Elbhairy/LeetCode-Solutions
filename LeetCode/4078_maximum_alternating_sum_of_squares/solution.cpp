/*
 * Problem Name: 4078. Maximum Alternating Sum Of Squares
 * Problem Link: https://leetcode.com/problems/maximum-alternating-sum-of-squares/
 */

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        long long ret = 0;
        int l = 0, r = n - 1;
        for (int i = 0; i < n; ++i) {
            if (i%2 == 0)
                ret += nums[r--];
            else
                ret -= nums[l++];
        }
        return ret;
    }
};
