/*
 * Problem Name: 3869. Smallest Index With Digit Sum Equal To Index
 * Problem Link: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
 */

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i =0;i<nums.size();++i){
            int sum = 0 ;
            while(nums[i]){
                sum += nums[i]%10;
                nums[i]/=10;
            }
            if(sum == i)return i;
        }
        return -1;
    }
};
