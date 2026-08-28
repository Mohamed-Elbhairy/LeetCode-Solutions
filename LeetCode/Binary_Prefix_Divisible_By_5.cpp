/*
 * Problem Name: Binary Prefix Divisible By 5
 * Problem Link: https://leetcode.com/problems/binary-prefix-divisible-by-5/
 */

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ret(nums.size());
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i];
            cur *= 2;
            while (cur >= 5)
                cur -= 5;
            if (cur == 0)
                ret[i] = true;
        }
        return ret;
    }
};
