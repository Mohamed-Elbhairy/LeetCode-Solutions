class Solution {
private:
    class DSU {
    private:
        vector<int> Parent;
        vector<int> mn;
        vector<int> mx;
        int Componantes;

    public:
        vector<int> GroupSize;
        
        DSU(int n) {
            Parent = vector<int>(n + 1);
            mn = vector<int>(n + 1);
            mx = vector<int>(n + 1);
            iota(Parent.begin(), Parent.end(), 0);
            iota(mn.begin(), mn.end(), 0);
            iota(mx.begin(), mx.end(), 0);
            GroupSize = vector<int>(n + 1, 1);
            Componantes = n;
        }
        int FindParent(int node) {
            if (Parent[node] == node)
                return node;
            return Parent[node] = FindParent(Parent[node]);
        }
        int GetGroupSize(int node) { return GroupSize[FindParent(node)]; }
        pair<int, int> Get(int u) {
            u = FindParent(u);
            return make_pair(mn[u], mx[u]);
        }
        void Merge(int u, int v) {
            u = FindParent(u);
            v = FindParent(v);
            if (u == v)
                return;
            if (GroupSize[u] < GroupSize[v])
                swap(u, v);
            Parent[v] = u;
            mn[u] = min(mn[u], mn[v]);
            mx[u] = max(mx[u], mx[v]);
            GroupSize[u] += GroupSize[v];
            Componantes--;
        }

        bool IsSameGroup(int u, int v) {
            return FindParent(u) == FindParent(v);
        }
    };

public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
      
        vector<int> l(n+10);
        for (int i = 0; i < n; ++i) {
            if (lights[i]) {
                int le = max(0,i-lights[i]);
                int r = min(n-1,i+lights[i]);
                l[le]++;
                l[r+1]--;
            }
        }
        for(int i =1;i<n;++i)l[i]+=l[i-1];
        int ans = 0;
       
        for(int i =0;i<n;){
            if(!l[i]){
                
                int j = i;
                int seg = 0 ;
                
                while(i<n && !l[i])++i ,++seg;
                
                ans += seg/3 +!!(seg%3);
               
              
            }
            else ++i;
        }
        return ans;
    }
};
