/*
 * Problem Name: Find Triangular Sum Of An Array
 * Problem Link: https://leetcode.com/problems/find-triangular-sum-of-an-array/
 */

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        while (n--) {
            for (int i = 0; i < n ; i++) {
                nums[i] = (nums[i]+nums[i+1]) % 10;
            }
        }
        return nums[0];
    }
};
