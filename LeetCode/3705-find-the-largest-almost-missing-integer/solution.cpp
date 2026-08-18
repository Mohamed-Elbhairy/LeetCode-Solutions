class Solution {
public:
    int largestInteger(vector<int>& v, int k) {
        set<int> st;
        map<int, int> mp;
        int l = 0, r = 0;
        int n = v.size();
        int anss = -1;
        map<int,int>ans;
        while (r < n) {
            mp[v[r]]++;
            if (mp[v[r]] == 1)
                st.insert(v[r]);
            while (r - l + 1 > k) {
                if (mp[v[l]] == 1)
                    st.erase(st.find(v[l]));
                else if (mp[v[l]] == 2)
                    st.insert(v[l]);
                mp[v[l]]--;
                l++;
            }
            if (r - l + 1 == k && st.size()) {
                for(int i : st)ans[i]++;
            }
            ++r;
        }
        for(auto [_,cnt] : ans){
            if(cnt==1)anss= _;
        }
        return anss;
    }
};
