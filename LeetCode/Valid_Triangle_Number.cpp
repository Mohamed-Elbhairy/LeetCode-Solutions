/*
 * Problem Name: Valid Triangle Number
 * Problem Link: https://leetcode.com/problems/valid-triangle-number/
 */

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin() , nums.end());
        for (int i = 0 ; i < nums.size() ; i++)
            for (int j = i+1 ; j < nums.size() ; j++)
                sum+=((nums.size() - (j+1) )- 
                (nums.end() - lower_bound(nums.begin() + j + 1 , nums.end() , nums[i] + nums[j])));
        return sum;
    }
};
