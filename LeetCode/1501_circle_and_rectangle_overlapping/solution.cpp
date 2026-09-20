/*
 * Problem Name: 1501. Circle And Rectangle Overlapping
 * Problem Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/
 */

class Solution {
public:
    bool checkOverlap(int r, int cx, int cy, int x1, int y1, int x2, int y2) {
        int x = clamp(cx, x1, x2) - cx;
        int y = clamp(cy, y1, y2) - cy;

        return x * x + y * y <= r * r;
    }
};
