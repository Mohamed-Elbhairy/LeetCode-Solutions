class Solution {
public:
    int numSub(string s) {
        long long ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0')
                continue;
            int j = i;
            while (j < s.size() && s[j] == '1')
                ++j;
            int n = j - i;
            ans = (ans + (1ll * (n) * (n + 1) / 2));
             i = j - 1;
        }
        while (ans >= 1e9 + 7)
            ans -= 1e9 + 7;
        return ans;
    }
};
