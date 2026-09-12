class Solution {
    vector<tuple<int, int, int, int>> v;
    vector<vector<pair<long long, vector<int>>>> dp; // dp[idx][rem]
    pair<long long, vector<int>> rec(int idx, int rem) {
        if (idx == v.size()) return make_pair(0LL, vector<int>());
        auto& ret = dp[idx][rem];
        if (~ret.first) return ret;
        ret = rec(idx + 1, rem);
        if (rem > 0) {
            auto [l, r, w, oldIdx] = v[idx];
            int nxt = lower_bound(v.begin(), v.end(), make_tuple(r + 1, -1, -1, -1)) - v.begin();
            auto X = rec(nxt, rem - 1);
            X.first += w;
            X.second.push_back(oldIdx);
            sort(X.second.begin(), X.second.end());
            if (ret.first < X.first) {
                ret = X;
            } else if (ret.first == X.first) {
                if (ret.second.empty() || ret.second > X.second) {
                    ret = X;
                }
            }
        }
        return ret;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        v.clear();
        for (int i = 0; i < intervals.size(); ++i) {
            v.push_back({ intervals[i][0], intervals[i][1], intervals[i][2], i });
        }
        sort(v.begin(), v.end());

        int n = v.size();
        dp.assign(n, vector<pair<long long, vector<int>>>(5, {-1, {}}));

        return rec(0, 4).second;
    }
};
