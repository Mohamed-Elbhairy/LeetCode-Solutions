/*
 * Problem Name: Sum Of Gcd Of Formed Pairs
 * Problem Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
 */

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            mx = max(mx, nums[i]);
            nums[i] = gcd(mx, nums[i]);
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        long long ret = 0;
        while (l < r) {
            ret += gcd(nums[l], nums[r]);
            ++l, --r;
        }
        return ret;
    }
};
