/*
 * Problem Name: 2210. Find Target Indices After Sorting Array
 * Problem Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/
 */

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        vector<int> ret;
        int cnt = 0;
        int cntT = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > target)
                continue;
            if (nums[i] == target)
                ++cntT;
            else
                cnt++;
        }
        for (int i = cnt; i < cnt + cntT; ++i)
            ret.push_back(i);
        return ret;
    }
};
