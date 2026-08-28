/*
 * Problem Name: Create Grid With Exactly One Path
 * Problem Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/
 */

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        swap(n,m);
        vector<string>v(n,string(m,'#'));
        for(int i =0;i<n;++i){
            v[i][0]='.';
        }
        for(int j =0;j<m;++j){
            v[n-1][j] = '.';
        }
        return v;
    }
};
