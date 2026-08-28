/*
 * Problem Name: Greatest Common Divisor Of Strings
 * Problem Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/
 */

class Solution {
    string gen(int sz, string& base) {
        string ret = "";
        while (sz) {
            ret += base;
            sz -= base.size();
        }
        return ret;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() > str2.size()) { // the left is the shortest
            swap(str1, str2);
        }
        string candidate = "";
        string ans = "";
        int len = gcd(str1.size(),str2.size()); // required length is the gcd
        for (int i = 0; i < len ; ++i) { 
            candidate += str1[i];
        }
        if (gen(str1.size(), candidate) == str1 &&
                gen(str2.size(), candidate) == str2) {
                ans = candidate;
        }
        return ans;
    }
};
