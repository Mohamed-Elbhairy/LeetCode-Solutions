class Solution {
public:
    const int mod = 1e9 + 7;
    inline int add(int a, int b) const {
        if (a >= mod)
            a -= mod;
        if (b >= mod)
            b -= mod;
        a += b;
        if (a >= mod)
            a -= mod;
        return a;
    }

    int lengthAfterTransformations(string& s, int t) {
        int dp[26][2];
        for (int i = 0; i < 26; ++i)
            dp[i][0] = dp[i][1] = 0;
        for (auto& i : s)
            dp[i - 'a'][1]++;
        int ans = 0;
        for (int i = 0; i < t; ++i) {
            for (int j = 0; j < 26; ++j)
                swap(dp[j][0], dp[j][1]);
            for (int j = 0; j < 26; ++j) {
                if (j == 25) {
                    dp[1][1] = add(dp[j][0], dp[1][1]);
                    dp[0][1] = add(dp[j][0], dp[0][1]);
                    dp[j][0] = 0;
                } else {
                    dp[j + 1][1] = dp[j][0];
                    dp[j][0] = 0;
                }
            }
        }
        for (auto& i : dp)
            ans = add(ans, i[1]);
        return ans;
    }
};
