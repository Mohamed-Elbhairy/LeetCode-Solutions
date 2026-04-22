class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ret = "";
        int idx = 0, idx1 = 0;
        bool x = 1;
        while (idx < word1.size() && idx1 < word2.size()) {
            if (x)
                ret += word1[idx++];
            else
                ret += word2[idx1++];
            x ^= 1;
        }
        while (idx < word1.size())
            ret += word1[idx++];
        while (idx1 < word2.size())
            ret += word2[idx1++];
        return ret;
    }
};
