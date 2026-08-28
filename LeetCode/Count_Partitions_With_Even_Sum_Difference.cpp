/*
 * Problem Name: Count Partitions With Even Sum Difference
 * Problem Link: https://leetcode.com/problems/count-partitions-with-even-sum-difference/
 */

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans = 0;
        int sum = 0, sum2 = 0;
        for (int& i : nums)
            sum += i;
        nums.pop_back();
        for (int& i : nums) {
            
            sum2 += i;
            sum -= i;
            if (abs(sum - sum2) % 2 == 0)
                ++ans;
        }
        return ans;
    }
};
