class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid[0].size();
        int m = grid.size();
        swap(n,m);
        int dp[n + 1][m + 1][k + 1];
        memset(dp, -1, sizeof(dp)) ;
        for(int i =0;i<=k;++i)dp[0][0][i] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int w = 0; w <= k; ++w) {
                    int gain = 0 ;
                    int cost = 0 ;
                    if(grid[i][j] == 1){
                        gain = 1;
                        cost = 1;
                    }
                    if(grid[i][j] == 2){
                        gain = 2;
                        cost = 1;
                    }
                    
                    if(i-1>=0 && w - cost >= 0 && dp[i-1][j][w-cost] !=-1){
                        dp[i][j][w] = max(dp[i-1][j][w-cost] + gain , dp[i][j][w]);
                    }
                    if(j-1>=0 && w - cost >= 0 && dp[i][j-1][w-cost] != -1 ){
                        dp[i][j][w] = max(dp[i][j-1][w-cost] + gain , dp[i][j][w]);
                    }
                }
            }
        }
        int ans = -1;
        for(int i =0;i<=k;++i){
            ans = max(ans,dp[n-1][m-1][i]);
        }
        return ans ; 
    }
};
