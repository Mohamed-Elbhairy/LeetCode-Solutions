class Solution {
public:
#define ll int
    struct SparseTable {

        vector<vector<int>> dp;
        vector<int> MSB;
        int skip = 0;
        int Merge(int a, int b) { return gcd(a, b); }
        void Build(vector<int>& v) {
            int n = v.size();

            for (int i = 2; i <= n; i++) {
                MSB[i] = MSB[(i >> 1LL)] + 1;
            }
            for (int i = 0; i < n; i++) {
                dp[i][0] = v[i];
            }
            for (int pw = 1; (1LL << pw) <= n; pw++) {
                for (int i = 0; i + (1LL << pw) <= n; i++) {
                    int X = i + ((1LL << (pw - 1)));
                    dp[i][pw] = Merge(dp[i][pw - 1], dp[X][pw - 1]);
                }
            }
        }

    public:
        SparseTable(vector<ll>& v) {
            int n = v.size();
            dp = vector<vector<int>>(n + 1, vector<int>(7));
            MSB = vector<int>(n + 1);
            Build(v);
        }
        ll Query(int l, int r) {
            int Len = r - l + 1;
            int ret = skip;
            ret = Merge(ret, dp[l][MSB[Len]]);
            ret = Merge(ret, dp[r - (1LL << MSB[Len]) + 1][MSB[Len]]);
            return ret;
        }
    };
    int minOperations(vector<int>& nums) {

        bool has1 = 0;
        SparseTable sparse(nums);
        int G = sparse.Query(0, nums.size() - 1);
        if (G != 1)
            return -1;
        int cnt = count(nums.begin(), nums.end(), 1);
        if (cnt)
            return nums.size() - cnt;
        int n = nums.size();
        int ans = n - 1;
        int l = 0, r = 0;
        while (r < n) {
            while (sparse.Query(l, r) == 1) {
                ans = min(ans, r - l);
                ++l;
            }
            ++r;
        }
        return (n - 1) + ans;
    }
};
