class Solution {
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp; 
    int rec (int i , int j , int k , vector<vector<int>>& grid , int  m , int n ,int sum){
        if (i == m-1 && j == n-1 )
            return ((sum+grid[i][j])%k == 0);
        if (i >= m || j >= n )
            return 0;
        int& ret = dp[i][j][sum];
        if (~ret)
            return ret;
        int ch1 = rec(i + 1 , j , k , grid , m , n , (sum+grid[i][j])%k );
        int ch2 = rec(i , j + 1, k , grid , m , n , (sum+grid[i][j])%k );
        return ret = (ch1 + ch2)%mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        dp.assign(m+1 , vector<vector<int>>(n+1 , vector<int>(k+1 , -1)));
        return rec(0 , 0 , k , grid , m , n , 0);
    }
};
