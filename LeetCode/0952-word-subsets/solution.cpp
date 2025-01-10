class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq[255] = {};
        for (auto &it : words2) {
            int freqt[26] = {};
            for (auto it1 : it)
                freqt[it1 - 'a']++;
            for (int i = 0; i < 26; i++)
                freq[i] = max(freq[i], freqt[i]);
        }
        words2.clear();
        for (auto &it : words1) {
            bool ok = 1;
            int freq1[26] = {};
            for (auto it1 : it)
                freq1[it1 - 'a']++;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > freq1[i]) {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                words2.push_back(it);
        }
        return words2;
    }
};
