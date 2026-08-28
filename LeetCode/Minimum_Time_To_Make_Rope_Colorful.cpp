/*
 * Problem Name: Minimum Time To Make Rope Colorful
 * Problem Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string &colors, vector<int>& neededTime) {
        int ret = 0;
        for (int i = 0; i < colors.size(); ++i) {
            int j = i;
            int mx = 0;
            int sum = 0;
            while (j < colors.size() && colors[i] == colors[j]) {
                sum += neededTime[j];
                mx = max(mx, neededTime[j]);
                ++j;
            }
            ret += (sum - mx);
            i = j - 1;
        }
        return ret ;
    }
};
