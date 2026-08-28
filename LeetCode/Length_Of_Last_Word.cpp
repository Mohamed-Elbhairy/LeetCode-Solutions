/*
 * Problem Name: Length Of Last Word
 * Problem Link: https://leetcode.com/problems/length-of-last-word/
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
       
        while( s.size() && s.back()==' ')s.pop_back();
        for(int i = s.size()-1 ; i>=0 ;--i){
            if(s[i] == ' ')return s.size() - i - 1 ;
        }
        return s.size();
    }
};
