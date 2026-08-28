/*
 * Problem Name: Find The Highest Altitude
 * Problem Link: https://leetcode.com/problems/find-the-highest-altitude/
 */

public class Solution {
    public int LargestAltitude(int[] gain) {

        int Sum = 0 ;
        int Mx = 0 ;
       foreach(var g in gain){
            Sum += g;
            Mx = Math.Max(Mx,Sum);
       }
       return Mx;
    }
}
