/*
 * Problem Name: Weighted Word Mapping
 * Problem Link: https://leetcode.com/problems/weighted-word-mapping/
 */

public class Solution {
    private int Sum(string word , int[] weights){
        int ret = 0 ;
        foreach(var c in word){
            int idx = c - 'a';
            ret += weights[idx];
        }
        return ret % 26;
    }
    public string MapWordWeights(string[] words, int[] weights) {
        string s = string.Empty;
        char[] alpha = new char[26];
        for(char c = 'a' ;c<='z';++c){
            alpha[(int)(c-'a')] =(char) ('z' - c +'a');
        }
        foreach(var word in words)
        {
            int val = Sum(word,weights) ;
            s += (char) (alpha[val]);

        }
        return s;
    }
}
