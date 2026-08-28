/*
 * Problem Name: Maximum Subarray Sum With Length Divisible By K
 * Problem Link: https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/
 */

using ll = long long;
class Solution {
public:
    ll maxSubarraySum(vector<int>& nums, int k) {       
        ll prefSum = 0;
        ll subMax = LLONG_MIN;
        vector<ll> minSoFar(k, LLONG_MAX / 2);
        minSoFar[(k - 1) % k] = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefSum += nums[i];
            subMax = max(subMax, prefSum - minSoFar[i % k]);
            minSoFar[i % k] = min(minSoFar[i % k], prefSum);
        }

        return subMax;
    }
};

