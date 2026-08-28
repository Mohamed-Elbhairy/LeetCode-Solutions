/*
 * Problem Name: Find Minimum Operations To Make All Elements Divisible By Three
 * Problem Link: https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
 */

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            ans += min(i % 3, 3 - (i % 3));
        }
        return ans;
    }
};
