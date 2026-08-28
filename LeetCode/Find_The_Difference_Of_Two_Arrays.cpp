/*
 * Problem Name: Find The Difference Of Two Arrays
 * Problem Link: https://leetcode.com/problems/find-the-difference-of-two-arrays/
 */

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ret(2);
        unordered_map<int,bool> freq1, freq2;
        for (int i : nums1)
            freq1[i] = 1;
        for (int i : nums2)
            freq2[i] = 1;
        for (int i : nums2)
            if (!freq1[i])
                ret[1].push_back(i), freq1[i] = 1;
        for (int i : nums1)
            if (!freq2[i])
                ret[0].push_back(i), freq2[i] = 1;
        return ret;
    }
};
