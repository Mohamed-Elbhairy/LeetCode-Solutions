/*
 * Problem Name: Length Of Longest V Shaped Diagonal Segment
 * Problem Link: https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n, m;
    int dx[5] = {0, 1, 1, -1, -1};
    int dy[5] = {0, 1, -1, 1, -1};
    int dp[501][501][4][5];
    int G[501][501];
    int X[5] = {0, 2, 4, 1, 3};
    bool Valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
    int rec(int i, int j, int state, int prev, int dir) {
        if ( !Valid(i, j) ) {
            return 0;
        }
        int &ret = dp[i][j][state][dir];
        if ( ~ret )
            return ret;
        ret = 0;
        if ( state == 1 ) {
            if ( i + 1 < n && j + 1 < m && G[i + 1][j + 1] == 2 ) {
                ret = max(ret, rec(i + 1, j + 1, 2, 1, 1) + 1);
            }
            if ( i + 1 < n && j - 1 >= 0 && G[i + 1][j - 1] == 2 ) {
                ret = max(ret, rec(i + 1, j - 1, 2, 1, 2) + 1);
            }
            if ( i - 1 >= 0 && j + 1 < m && G[i - 1][j + 1] == 2 ) {
                ret = max(ret, rec(i - 1, j + 1, 2, 1, 3) + 1);
            }
            if ( i - 1 >= 0 && j - 1 >= 0 && G[i - 1][j - 1] == 2 ) {
                ret = max(ret, rec(i - 1, j - 1, 2, 1, 4) + 1);
            }
        }
        if ( state == 2 ) {
            int gain = Valid(i + dx[dir], j + dy[dir]);
            if ( (gain && ((G[i][j] == 2 && G[i + dx[dir]][j + dy[dir]] == 0) ||
                           (G[i][j] == 0 && G[i + dx[dir]][j + dy[dir]] == 2))) ||
                 !gain )
                ret = max(ret, rec(i + dx[dir], j + dy[dir], state, G[i][j], dir) + gain);
            int ni = i + dx[X[dir]];
            int nj = j + dy[X[dir]];
            bool Gain = Valid(ni, nj);
            if ( (!Gain) || (Gain && ((G[i][j] == 2 && G[ni][nj] == 0) || (G[i][j] == 0 && G[ni][nj] == 2))) )
                ret = max(ret, rec(ni, nj, 3, G[i][j], X[dir]) + Gain);
        }
        if ( state == 3 ) {
            int gain = Valid(i + dx[dir], j + dy[dir]);
            if ( (gain && ((G[i][j] == 2 && G[i + dx[dir]][j + dy[dir]] == 0) ||
                           (G[i][j] == 0 && G[i + dx[dir]][j + dy[dir]] == 2))) ||
                 !gain )
                ret = max(ret, rec(i + dx[dir], j + dy[dir], state, G[i][j], dir) + gain);
        }
        return ret;
    }
    // topleft => i-1,j-1=>4 => topright => i-1,j+1 , 3
    // topright=>i-1,j+1=>3 => botrigh => i+1,j+1 , 1
    // bottomleft=>i+1,j-1=>2 , topleft => i-1,j-1 , 4
    // bottomright=>i+1,j+1=>1 , botleft => i +1 , j-1 ,2
    int lenOfVDiagonal(vector< vector< int > > &grid) {
        memset(dp, -1, sizeof(dp));
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < m; j++ )
                G[i][j] = grid[i][j], ans = max(ans, int(G[i][j] == 1));
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                if ( G[i][j] == 1 ) {
                    ans = max(ans, rec(i, j, 1, 0, 0)+1);
                }
            }
        }
        return ans;
    }
};

