class Solution {
    bool IsVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'e' ||
               c == 'u';
    }

public:
    string reverseVowels(string s) {
        int l = 0,  r = s.size() - 1;
        while (l < r) {
            while (l < s.size() && !IsVowel(s[l]))
                ++l;
            while (r >= 0 && !IsVowel(s[r]))
                --r;
            if (l<r && IsVowel(s[l]) && IsVowel(s[r])) {
                swap(s[l], s[r]);
                ++l,--r;
            }
            
        }
        return s;
    }
};
