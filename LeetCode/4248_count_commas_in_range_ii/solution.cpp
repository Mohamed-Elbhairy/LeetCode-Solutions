/*
 * Problem Name: 4248. Count Commas In Range Ii
 * Problem Link: https://leetcode.com/problems/count-commas-in-range-ii/
 */

class Solution {
public:
    long long countCommas(long long n) {
        long long ret = 0;
       
        for(long long i =1000;i<=n;i*=1000){
            if(n>=i)ret += n - (i-1);
        }
       
        return ret;
    }
};
