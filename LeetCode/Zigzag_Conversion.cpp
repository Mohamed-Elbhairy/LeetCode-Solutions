/*
 * Problem Name: Zigzag Conversion
 * Problem Link: https://leetcode.com/problems/zigzag-conversion/
 */

class Solution {
public:
    string convert(string s, int r) {
        if(r==1)return s;
        vector<string>ans(r);
        int shift=0;
        bool x =1 ;
        int n = s.size();
        int cnt =0 ;
        //P A Y P A L I S H I R  I  N  G
        //0 1 2 3 4 5 6 7 8 9 10 11 12 13
        //0 1 2 1 0 1 2 1 0 1 2  1  0  1  
        // ((i-shift)+r)%r 
        for(int i = 0 ; i < n ;i++){
            ans[shift]+=s[i];
            if(shift==r-1)x=0;
            else if(shift==0)x=1;
            if(x)shift++;
            else shift--;
        }
        string anss="";
        for(int i=0;i<r;i++){
            for(auto it:ans[i])anss+=it;
        }
        return anss;
    }

};
