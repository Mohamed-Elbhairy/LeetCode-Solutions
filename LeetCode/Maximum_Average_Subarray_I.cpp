/*
 * Problem Name: Maximum Average Subarray I
 * Problem Link: https://leetcode.com/problems/maximum-average-subarray-i/
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int mx = -1e9;
        int l = 0, r = 0;
        int sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            if (r - l + 1 > k)
                sum -= nums[l++];
            if (r - l + 1 == k)
                mx = max(sum, mx);
            ++r;
        }
        return double(double(mx)/ k);
    }
};
