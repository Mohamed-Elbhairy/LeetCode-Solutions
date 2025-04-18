class Solution {
private:
    int dp[2001][2001];
    string s, t;
    int rec(int i, int j) {
        if (i == s.size() and j == t.size())
            return 0;
        if (i + j > s.size() + t.size())
            return i + j + 1000;
        int& ret = dp[i][j];
        if (~ret)
            return ret;
        ret = s.size() + t.size() + 1000;

        if (i < s.size() and j < t.size() and s[i] == t[j])
            ret = min(ret, rec(i + 1, j + 1) + 1);
        if (i < s.size())
            ret = min(ret, rec(i + 1, j) + 1);
        if (j < t.size())
            ret = min(ret, rec(i, j + 1) + 1);

        return ret;
    }
    string ans;
    void Bulid(int i, int j) {
        if (i == s.size() and j == t.size())
            return;
        if (i + j > s.size() + t.size())
            return;
        int& ret = dp[i][j];

        if (ret == rec(i + 1, j + 1) + 1 and i < s.size() and j < t.size() and
            s[i] == t[j]) {
            ans += s[i];
            Bulid(i + 1, j + 1);
            return;
        }
        if (ret == rec(i + 1, j) + 1 and i < s.size()) {
            ans += s[i];
            Bulid(i + 1, j);
            return;
        }
        if (ret == rec(i, j + 1) + 1 and j < t.size()) {
            ans += t[j];
            Bulid(i, j + 1);
            return;
        }
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        s = str1, t = str2;
        memset(dp, -1, sizeof dp);
        rec(0, 0);
        Bulid(0, 0);
        return ans;
    }
};
