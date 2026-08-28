/*
 * Problem Name: Shortest And Lexicographically Smallest Beautiful String
 * Problem Link: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
 */

class Solution {
public:
    string shortestBeautifulSubstring(string& s, int k) {
        string ans = s;
        bool isOk = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (j - i + 1 > ans.size())
                    continue;
                string tmp = "";
                int cnt = 0;
                for (int t = i; t <= j; ++t) {
                    if (s[t] == '1')
                        ++cnt;
                    tmp += s[t];
                }
                if (cnt == k) {
                    isOk = 1;
                    if( ans.size()>tmp.size() )ans = tmp;
                    else ans = min(ans, tmp);
                }
            }
        }
        return isOk ? ans : "";
    }
};
