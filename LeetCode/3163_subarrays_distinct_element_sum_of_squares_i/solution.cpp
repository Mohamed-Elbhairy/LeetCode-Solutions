/*
 * Problem Name: 3163. Subarrays Distinct Element Sum Of Squares I
 * Problem Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
 */

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                seen.insert(nums[j]);
                int d = seen.size();
                ans += d * d;
            }
        }

        return ans;
    }
};
