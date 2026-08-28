/*
 * Problem Name: Find The Maximum Sum Of Node Values
 * Problem Link: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/
 */

class Solution {
public:
    using ll = long long;
    vector<vector<ll>> dp;
    ll rec(int idx, bool X, int k, vector<int>& v) {
        int n = v.size();
        if (idx == n)
            return (X == 0) ? 0 : -1e15;
        ll& ret = dp[idx][X];
        if (~ret)
            return ret;
        ret = rec(idx + 1, X, k, v) + v[idx];
        ret = max(rec(idx + 1, X ^ 1, k, v) + (v[idx] ^ k), ret);
        return ret;
    }
    long long maximumValueSum(vector<int>& v, int k,
                              vector<vector<int>>& edges) {
        dp = vector<vector<ll>>(v.size() + 1, vector<ll>(3, -1));
        return rec(0, 0, k, v);
    }
};
