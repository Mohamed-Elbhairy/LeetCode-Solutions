/*
 * Problem Name: Happy Number
 * Problem Link: https://leetcode.com/problems/happy-number/
 */

class Solution {
private:
    unordered_map<int, bool> mp;

public:
    bool isHappy(int n) {
        if (mp.count(n))
            return false;
        if (n == 1)
            return true;
        mp[n] = 1;
        int x = 0;
        while (n) {
            x += (n % 10) * (n % 10);
            n /= 10;
        }
        return isHappy(x);
    }
};
