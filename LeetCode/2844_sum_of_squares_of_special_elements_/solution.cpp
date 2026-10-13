/*
 * Problem Name: 2844. Sum Of Squares Of Special Elements 
 * Problem Link: https://leetcode.com/problems/sum-of-squares-of-special-elements-/
 */

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums.size() % (i + 1) == 0)
                ans += nums[i] * nums[i];
        }
        return ans;
    }
};
