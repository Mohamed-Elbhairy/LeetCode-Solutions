class Solution {
private:
    const int N = 201, MOD = 1e9 + 7;
    int dp[201][201][201];
    int n;
    vector<int> v;
    int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
    int rec(int i, int g1, int g2) {
        if (i == n)
            return (g1 == g2 && g1 > 0);
        int& ret = dp[i][g1][g2];
        if (~ret)
            return ret;
        ret = 0;
        ret = add(ret, rec(i + 1, g1, g2));
        ret = add(ret, rec(i + 1, gcd(g1, v[i]), g2));
        ret = add(ret, rec(i + 1, g1, gcd(g2, v[i])));
        return ret;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof dp);
        v = nums;
        return rec(0, 0, 0);
    }
};
