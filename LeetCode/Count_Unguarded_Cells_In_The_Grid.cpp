/*
 * Problem Name: Count Unguarded Cells In The Grid
 * Problem Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
 */

class Solution {
    void dfs(int m, int n, vector<vector<char>>& vis, int i, int j,
             pair<int, int> dir) {
        if (i >= m || i < 0 || j >= n || j < 0 || vis[i][j] == 'w' ||
            (vis[i][j] == 'g' && (!(dir.second == 0 && dir.first == 0))))
            return;
        if (vis[i][j] == 'g') {
            dfs(m, n, vis, i, j + 1, {0, 1});
            dfs(m, n, vis, i, j - 1, {0, -1});
            dfs(m, n, vis, i - 1, j, {-1, 0});
            dfs(m, n, vis, i + 1, j, {1, 0});
        } else
            vis[i][j] = '#', dfs(m, n, vis, i + dir.first, j + dir.second, dir);
        return;
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        int ans = 0;
        vector<vector<char>> vis(m, vector<char>(n, '.'));
        for (int i = 0; i < guards.size(); i++)
            vis[guards[i][0]][guards[i][1]] = 'g';
        for (int i = 0; i < walls.size(); i++)
            vis[walls[i][0]][walls[i][1]] = 'w';
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 'g')
                    dfs(m, n, vis, i, j, {0, 0});
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == '.')
                    ans++;
            }
        }
        return ans;
    }
};
