class Solution {
public:
    int canBeTypedWords(string s, string brokenLetters) {
        int mask = 0;
        for (auto& i : brokenLetters)
            mask |= 1 << (i - 'a');
        int ret = count(s.begin(),s.end(),' ')+1;
        bool newWord = false;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            while (i < n && s[i] != ' ') {
                if (mask & (1 << (s[i] - 'a'))) {
                    ret--;
                    while (i < n && s[i] != ' ')
                        ++i;
                    break;
                }
                ++i;
            }
        }
        return ret;
    }
};
