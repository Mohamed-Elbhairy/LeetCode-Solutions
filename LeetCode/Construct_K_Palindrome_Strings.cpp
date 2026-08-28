/*
 * Problem Name: Construct K Palindrome Strings
 * Problem Link: https://leetcode.com/problems/construct-k-palindrome-strings/
 */

class Solution {
public:
    bool canConstruct(string &s, int &k) {
        if(s.length()==k)return 1;
        if(s.length()< k)return 0;
        int freq[26] = {};
        for (auto& i : s)
            freq[i - 'a']++;
        int odd = 0;
        for (int i = 0; i < 26; i++)
            odd += !!(freq[i] & 1);
       
       return odd<=k ;
        
        
    }
};
