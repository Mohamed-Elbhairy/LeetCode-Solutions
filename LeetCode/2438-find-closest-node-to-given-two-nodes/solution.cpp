class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& dis) {
        for (auto& neg : adj[node]) {
            if (dis[node] + 1 < dis[neg]) {
                dis[neg] = dis[node] + 1;
                dfs(neg, adj, dis);
            }
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> dis1(n + 1, 1e9);
        vector<int> dis2(n + 1, 1e9);

        dis1[node1] = 0;
        dis2[node2] = 0;

        for (int i = 0; i < n; ++i) {
            if (edges[i] == -1)
                continue;

            adj[i].push_back(edges[i]);
        }

        dfs(node1, adj, dis1);
        dfs(node2, adj, dis2);

        int ans = 1e9;
        int ansNode = -1;
        for (int i = 0; i < n; ++i) {
            if (dis1[i] == 1e9 || dis2[i] == 1e9)
                continue;
            int Mx = max(dis1[i], dis2[i]);
            if (ans > Mx) {
                ans = Mx;
                ansNode = i;
            }
        }
        return ansNode;
    }
};
