/*
 * Problem Name: Set Mismatch
 * Problem Link: https://leetcode.com/problems/set-mismatch/
 */

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ind(nums.size() + 1, -1);
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (ind[nums[i]] != -1) {
                ret.push_back(nums[i]);
                continue;
            }
            ind[nums[i]] = i;
        }
        for (int i = 1; i <= n; ++i) {
            if (ind[i] == -1) {
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
};
