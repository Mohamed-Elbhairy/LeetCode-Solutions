/*
 * Problem Name: Count Odd Numbers In An Interval Range
 * Problem Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
 */

class Solution {
public:
    int countOdds(int &low, int &high) { return (++high >> 1) - (low >> 1); }
};
