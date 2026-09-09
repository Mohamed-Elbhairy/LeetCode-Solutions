/*
 * Problem Name: 0492. Construct The Rectangle
 * Problem Link: https://leetcode.com/problems/construct-the-rectangle/
 */

class Solution {
public:
   vector<int> constructRectangle(int area) {
        int sq = sqrt(area);
        while(area%sq)--sq;
        return {area/sq,sq};
    }
};
