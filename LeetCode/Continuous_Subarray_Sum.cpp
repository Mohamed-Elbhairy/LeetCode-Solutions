/*
 * Problem Name: Continuous Subarray Sum
 * Problem Link: https://leetcode.com/problems/continuous-subarray-sum/
 */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        map<long long, long long>mp;
        mp[0]=-1;
         if (nums.size() == 1)return 0;
        if (k == 1 && nums.size() > 1)return true;
            for (int i = 0; i < nums.size(); i++) {
                sum += (nums[i]%k);
               sum %= k;
               
                if (mp.count(sum)) {
                    if (abs(i - mp[sum]) > 1) {
                        return 1;
                    }
                }
                else {
                  mp[sum] = i;
                    
                }
            }
        return 0;
    }
};
