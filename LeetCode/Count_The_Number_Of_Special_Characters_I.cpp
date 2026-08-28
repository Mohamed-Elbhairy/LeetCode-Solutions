/*
 * Problem Name: Count The Number Of Special Characters I
 * Problem Link: https://leetcode.com/problems/count-the-number-of-special-characters-i/
 */

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_set<char> st(word.begin(), word.end());

        int count = 0;

        for(char ch = 'a'; ch <= 'z'; ch++) {

            if(st.count(ch) && st.count(ch - 'a' + 'A')) {
                count++;
            }
        }

        return count;
    }
};
