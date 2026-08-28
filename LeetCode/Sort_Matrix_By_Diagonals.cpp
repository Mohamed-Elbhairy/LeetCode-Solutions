/*
 * Problem Name: Sort Matrix By Diagonals
 * Problem Link: https://leetcode.com/problems/sort-matrix-by-diagonals/
 */

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (i == 0)
                continue;
            int ni = 0, nj = i;
            while (ni < n && nj < n) {

                v.push_back(grid[ni++][nj++]);
            }
            sort(v.rbegin(), v.rend());
            ni = 0, nj = i;
            while (ni < n && nj < n) {
                grid[ni++][nj++] = v.back();
                v.pop_back();
            }
        }
        for (int i = 0; i < n; ++i) {
            int ni = i, nj = 0;
            while (ni < n && nj < n) {
                v.push_back(grid[ni++][nj++]);
            }
            sort(v.begin(), v.end());
            ni = i, nj = 0;
            while (ni < n && nj < n) {
                grid[ni++][nj++] = v.back();
                v.pop_back();
            }
        }

        return grid;
    }
};
