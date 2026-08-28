/*
 * Problem Name: Power Grid Maintenance
 * Problem Link: https://leetcode.com/problems/power-grid-maintenance/
 */

class Solution {
    class DSU {
    private:
        vector<int> Parent;
        vector<set<int>> members;
        vector<int> GroupSize;
        int Componantes;
        set<int> dels;

    public:
        DSU(int n) {
            Parent = vector<int>(n + 1);
            iota(Parent.begin(), Parent.end(), 0);
            GroupSize = vector<int>(n + 1, 1);
            members = vector<set<int>>(n + 1);
            for (int i = 1; i <= n; ++i) {
                members[i].insert(i);
            }
            Componantes = n;
        }
        int FindParent(int node) {
            if (Parent[node] == node)
                return node;
            return Parent[node] = FindParent(Parent[node]);
        }
        int GetGroupSize(int node) { return GroupSize[FindParent(node)]; }
        void Merge(int u, int v) {
            u = FindParent(u);
            v = FindParent(v);
            if (u == v)
                return;
            if (GroupSize[u] < GroupSize[v])
                swap(u, v);
            for (auto& c : members[v]) {
                members[u].insert(c);
            }
            Parent[v] = u;
            GroupSize[u] += GroupSize[v];
            Componantes--;
        }
        int Get(int u) {
            if (dels.count(u)) {
                u = FindParent(u);
                return (members[u].size() ? *members[u].begin() : -1);
            }
            return u;
        }
        void del(int u) {
            dels.insert(u);
            int p = FindParent(u);
            members[p].erase(u);
        }
        void add(int u) {
            int p = FindParent(u);
            members[p].insert(u);
        }
        bool IsSameGroup(int u, int v) {
            return FindParent(u) == FindParent(v);
        }
    };

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto it : connections) {
            dsu.Merge(it[0], it[1]);
        }
        vector<int> ret;
        for (auto it : queries) {
            int op = it[0];
            int node = it[1];
            if (op == 1) {
                ret.push_back(dsu.Get(node));
            }
            if (op == 2) {
                dsu.del(node);
            }
        }
        return ret;
    }
};
