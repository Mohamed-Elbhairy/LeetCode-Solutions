/*
 * Problem Name: 0453. Minimum Moves To Equal Array Elements
 * Problem Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0ll) - (nums.size() * ranges::min(nums));
    }
};
