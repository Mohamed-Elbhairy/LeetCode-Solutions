/*
 * Problem Name: Two Sum
 * Problem Link: https://leetcode.com/problems/two-sum/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int idx = mp[target - nums[i]];
            if (idx != 0) {
                return {i, idx - 1};
            }
            mp[nums[i]] = i + 1;
        }
        return {};
    }
};
