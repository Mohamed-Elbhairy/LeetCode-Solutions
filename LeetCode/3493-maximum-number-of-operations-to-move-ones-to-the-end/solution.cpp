class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int ans = 0;
        int cnt0 = 0;
        for (int i = 0; i < n; ++i) {
            cnt0 += s[i] == '0' ? 1 : 0;
        }
        int curones = 0; // 1 00 1101 | cnt0 = 1;| cur = 3  | ans = 1 + 3 ;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                --cnt0;
                continue;
            }
            int j = i;
            while (j < n && s[j] == '1') {
                ++j;
            }
            if (cnt0) {
                curones += j - i;
                ans += curones;
            } 
            else
                break;

            i = j - 1;
        }
        return ans;
    }
};
