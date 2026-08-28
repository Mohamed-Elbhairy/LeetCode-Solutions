/*
 * Problem Name: Longest Substring Without Repeating Characters
 * Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[255]={};
        int l=0,r=0;
        int cnt =0 ;
        int ans =0 ;
        while(r<s.size()){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l++]]--;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }

};
