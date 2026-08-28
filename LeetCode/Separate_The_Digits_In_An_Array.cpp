/*
 * Problem Name: Separate The Digits In An Array
 * Problem Link: https://leetcode.com/problems/separate-the-digits-in-an-array/
 */

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ret;
        for (int i : nums) {
            vector<int> v1;
            while (i) {
                v1.push_back(i % 10);
                i /= 10;
            }
            reverse(v1.begin(), v1.end());
            for (int j : v1)
                ret.push_back(j);
        }
        return ret;
    }
};
