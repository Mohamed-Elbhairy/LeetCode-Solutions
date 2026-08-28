/*
 * Problem Name: Find Closest Person
 * Problem Link: https://leetcode.com/problems/find-closest-person/
 */

class Solution {
public:
    int findClosest(int x, int y, int z) {
        x = abs(x - z);
        y = abs(z - y);
        if (x > y)
            return 2;
        if (x < y)
            return 1;
        return 0;
    }
};
