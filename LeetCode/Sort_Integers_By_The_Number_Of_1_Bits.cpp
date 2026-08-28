/*
 * Problem Name: Sort Integers By The Number Of 1 Bits
 * Problem Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
 */

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> v(20);
        for (int& i : arr) {
            int cnt = 0;
            int t = i;
            while (i) {
                cnt += i % 2;
                i /= 2;
            }
            v[cnt].push_back(t);
        }
        vector<int> ret;
        for (int i = 0; i < 20; ++i) {
            sort(v[i].begin(), v[i].end());
            for (int j : v[i]) {
                ret.push_back(j);
            }
        }
        return ret;
    }
};
