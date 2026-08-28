/*
 * Problem Name: Maximize The Number Of Target Nodes After Connecting Trees I
 * Problem Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/
 */

class Solution {
private:
    void dfs(int node, int parent, int dis, int &X, int &k, vector<int>& CountNodesLessThank,
             vector<vector<int>>& adj) {
        if (dis <= k)
            CountNodesLessThank[X]++;
        for (auto& child : adj[node]) {
            if (child != parent)
                dfs(child, node, dis + 1, X, k, CountNodesLessThank, adj);
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj(n + 1);
        vector<vector<int>> adj1(m + 1);

        vector<int> CountNodesLessThankTree1(n + 1);
        vector<int> CountNodesLessThankTree2(m + 1);

        for (auto& it : edges1) {
            int u = it[0] + 1;
            int v = it[1] + 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (auto& it : edges2) {
            int u = it[0] + 1;
            int v = it[1] + 1;
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        int k1 = k-1;
        for (int i = 1; i <= m; ++i) {
            dfs(i, i, 0, i, k1, CountNodesLessThankTree2, adj1);
        }
        int mx = 0;
        for (int i = 1; i <= m; ++i)
            mx = max(mx, CountNodesLessThankTree2[i]);

        vector<int> ret;

        for (int i = 1; i <= n; i++) {
            dfs(i, i, 0, i, k, CountNodesLessThankTree1, adj);
            ret.push_back(CountNodesLessThankTree1[i] + mx);
        }
        return ret;
    }
};
