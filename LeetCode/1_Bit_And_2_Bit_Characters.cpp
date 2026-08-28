/*
 * Problem Name: 1 Bit And 2 Bit Characters
 * Problem Link: https://leetcode.com/problems/1-bit-and-2-bit-characters/
 */

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int cnt = 0;
        if (bits.back() == 1)
            return false;
        int i = bits.size() - 2;
        while (i >= 0 && bits[i] == 1)
            cnt++ , i--;
        return (cnt%2 == 0 );

    }
};
