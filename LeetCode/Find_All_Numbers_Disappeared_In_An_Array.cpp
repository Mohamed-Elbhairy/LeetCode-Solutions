/*
 * Problem Name: Find All Numbers Disappeared In An Array
 * Problem Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1), ret;
        for (int i = 0; i < n; ++i) {
            f[nums[i]] = 1;
        }
        for (int i =1 ; i <= n; ++i) {
            if (f[i])
                continue;
            ret.push_back(i);
        }
        return ret;
    }
};
