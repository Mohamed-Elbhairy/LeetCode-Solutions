class Solution {
public:
    int maxFreqSum(string s) {
        int mask = 0;
        mask |= 1 << ('a' - 'a');
        mask |= 1 << ('i' - 'a');
        mask |= 1 << ('o' - 'a');
        mask |= 1 << ('u' - 'a');
        mask |= 1 << ('e' - 'a');
        vector<int> freq(26);
        for (auto& c : s) {
            freq[c - 'a']++;
        }
        int ans = 0, ans1 = 0;
        for (auto& c : s) {
            if ((mask & (1 << (c - 'a'))))
                ans = max(ans, freq[c - 'a']);
            else
                ans1 = max(ans1, freq[c - 'a']);
        }
        return ans + ans1;
    }
};
