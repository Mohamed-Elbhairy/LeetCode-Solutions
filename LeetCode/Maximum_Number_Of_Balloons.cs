/*
 * Problem Name: Maximum Number Of Balloons
 * Problem Link: https://leetcode.com/problems/maximum-number-of-balloons/
 */

public class Solution {
    public int MaxNumberOfBalloons(string text) {
        int b = 0 , a = 0 , l =0 ,o = 0 , n =0;
        foreach(var c in text){
            if(c == 'a')++a;
            if(c == 'o')++o;
            if(c == 'l')++l;
            if(c == 'b')++b;
            if(c == 'n')++n;
        }
        l/=2;
        o/=2;
       var ch = new List<int>{a,b,l,o,n};
        return ch.Min();
    }
}
