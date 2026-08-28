/*
 * Problem Name: Sort Vowels In A String
 * Problem Link: https://leetcode.com/problems/sort-vowels-in-a-string/
 */

class Solution {
public:
    string sortVowels(string& s) {
        int freq[255] = {0};
        const char vowels[] = {'A', 'E', 'I', 'O', 'U',
                               'a', 'e', 'i', 'o', 'u'};

        int idx = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            freq[s[i]]++;
        }
        bool IsVowel[255] = {0};
        for (int i = 0; i < 10; ++i)
            IsVowel[vowels[i]] = true;
        for (int i = 0; i < n; ++i) {
            bool Ok = IsVowel[s[i]] ;
            if (Ok) {
                while (idx < 10 && !freq[vowels[idx]])
                    ++idx;
                if (idx == 10)
                    break;
                s[i] = vowels[idx];
                freq[vowels[idx]]--;
            }
        }
        return s;
    }
};
