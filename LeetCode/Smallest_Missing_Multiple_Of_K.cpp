/*
 * Problem Name: Smallest Missing Multiple Of K
 * Problem Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/
 */

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int freq[101] = {};
        for (int i : nums)
            freq[i]++;
        int ans = k;
        while (true) {
            if (ans >100 || !freq[ans])
                return ans;
            ans += k;
        }
        return 0;
    }
};
