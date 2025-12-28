class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int lst = m-1;
        int ans = 0;
        for (int i = 0; i < n; ++i){

            while(lst >= 0 &&grid[i][lst]<0){
                --lst;
            }
            ans += m - lst - 1;
        }
        return ans ; 
    }
};
