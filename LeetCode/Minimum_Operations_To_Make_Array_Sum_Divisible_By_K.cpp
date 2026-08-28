/*
 * Problem Name: Minimum Operations To Make Array Sum Divisible By K
 * Problem Link: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        ans=sum%k;
        return ans;
    }
};
