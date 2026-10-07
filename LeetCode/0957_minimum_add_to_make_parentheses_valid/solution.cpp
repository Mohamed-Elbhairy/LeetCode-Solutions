/*
 * Problem Name: 0957. Minimum Add To Make Parentheses Valid
 * Problem Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0 ;
        int ans= 0 ;
        for(char c:s){
            if(c == '(')++cnt;
            else {
                if(cnt == 0)++ans;
                else --cnt;
            }
        }
        ans += cnt;
        return ans;
    }
};
