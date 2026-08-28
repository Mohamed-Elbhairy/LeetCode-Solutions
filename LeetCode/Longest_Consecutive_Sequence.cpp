/*
 * Problem Name: Longest Consecutive Sequence
 * Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int ret = 1;
        unordered_map<int, bool> freq;
        for (int i : nums) {
            freq[i] = 1;
        }
        for (int i : nums) {
            if (freq[i] == 0)
                continue;
            int len = 1;
            int tempVal = i;
            while (freq[tempVal + 1] ) {
                freq[tempVal] = 0;
                tempVal++;
                ++len;
            }
            tempVal = i;
            while (freq[tempVal - 1]) {
                freq[tempVal] = 0;
                tempVal--;
                ++len;
            }
            ret = max(ret, len);
        }
        return ret;
    }
};
