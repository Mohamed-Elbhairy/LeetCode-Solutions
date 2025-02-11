class Solution {
public:
    string removeOccurrences(string s, string s1) {

        int n, m;
        n = s.size(), m = s1.size();
        int freq[26] = {0}, f[26] = {0};
        for (auto& i : s1)
            freq[i - 'a']++;
        for (auto& i : s)
            if (freq[i - 'a'])
                f[i - 'a']++;
        int mn = min(*max_element(f, f + 26), (n / m) + 1), ans = 0;
        while (mn--) {
            int p = s.find(s1);
            if (p == string::npos)
                break;
            ans++;
            s.erase(p, m);
        }
        return s;
    }
};
