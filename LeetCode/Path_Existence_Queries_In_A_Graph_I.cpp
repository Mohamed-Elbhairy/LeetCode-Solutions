/*
 * Problem Name: Path Existence Queries In A Graph I
 * Problem Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
 */

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> id(n);
        int curid = 0;
        for (int i = 1; i < n; ++i) {
            if(nums[i] - nums[i-1] <=maxDiff){
                id[i] = id[i-1];
            }
            else id[i] = ++curid;
        }
        vector<bool>ans;
        for(auto q : queries){
            int u = q[0];
            int v = q[1];
           ans.push_back(id[u] == id[v]);
        }
        return ans;
    }
};
