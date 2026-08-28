/*
 * Problem Name: Equal Row And Column Pairs
 * Problem Link: https://leetcode.com/problems/equal-row-and-column-pairs/
 */

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        map<vector<int>, int> freq;

        int n = grid.size();

        for (int i = 0; i < n; ++i)
            freq[grid[i]]++;

        int ret = 0;

        for (int j = 0; j < n; ++j) {
            vector<int> vec;
            for (int i = 0; i < n; ++i) {
                vec.push_back(grid[i][j]);
            }
            ret += freq[vec];
        }
        return ret;
    }
};
