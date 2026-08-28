/*
 * Problem Name: How Many Numbers Are Smaller Than The Current Number
 * Problem Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] < nums[i]) {
                    ret[i]++;
                }
            }
        }
        return ret;
    }
};
