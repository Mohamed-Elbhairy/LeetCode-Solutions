/*
 * Problem Name: Check If All 1S Are At Least Length K Places Away
 * Problem Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
 */

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                if (last == -1)
                    last = i;
                else {
                    if (i - last - 1 < k)
                        return false;
                    last = i;
                }
            }
        }
        return true;
    }
};
