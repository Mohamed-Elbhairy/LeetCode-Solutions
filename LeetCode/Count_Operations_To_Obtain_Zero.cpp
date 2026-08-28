/*
 * Problem Name: Count Operations To Obtain Zero
 * Problem Link: https://leetcode.com/problems/count-operations-to-obtain-zero/
 */

class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1 == 0 || num2 == 0)
            return 0;

        if (num1 >= num2) {
            return 1 + countOperations(num1 - num2, num2);
        }
        return 1 + countOperations(num1, num2 - num1);
    }
};
