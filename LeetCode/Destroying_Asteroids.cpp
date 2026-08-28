/*
 * Problem Name: Destroying Asteroids
 * Problem Link: https://leetcode.com/problems/destroying-asteroids/
 */

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& astrs) {
        sort(astrs.begin(), astrs.end());
        long long sum = mass;
        for (int astr : astrs) {
            if (astr > sum)
                return false;
            sum += astr;
        }
        return true;
    }
};
