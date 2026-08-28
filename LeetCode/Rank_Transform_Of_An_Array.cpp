/*
 * Problem Name: Rank Transform Of An Array
 * Problem Link: https://leetcode.com/problems/rank-transform-of-an-array/
 */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        for(int i : arr)mp[i] = 1;

        int st = 1;
        for(auto &it :mp){
            it.second = st++;
        }
        for(int &i :arr)i = mp[i];
        return arr;

    }
};
