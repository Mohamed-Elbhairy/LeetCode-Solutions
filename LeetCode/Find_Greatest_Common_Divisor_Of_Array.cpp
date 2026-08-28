/*
 * Problem Name: Find Greatest Common Divisor Of Array
 * Problem Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
 */

class Solution {
public:
    int findGCD(vector<int>& nums) {
      int mn = 1e9 , mx = 0;
      for(int &i : nums){
        mx = max(mx,i);
        mn = min(mn,i);
      }   
      return gcd(mx,mn);
    }
};
