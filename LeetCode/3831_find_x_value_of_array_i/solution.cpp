/*
 * Problem Name: 3831. Find X Value Of Array I
 * Problem Link: https://leetcode.com/problems/find-x-value-of-array-i/
 */

class Solution {
public:
    vector<long long> resultArray(vector<int>& A, int k) {
        vector<long long> res(k);
        int freq[5] = {0};

        for (auto& n : A) {
            n %= k;
            int cur[5] = {0}; 

            cur[n] = 1;

            for (int x = 0; x < k; x++)
                cur[x * n % k] += freq[x];

            for (int x = 0; x < k; x++) {
                freq[x] = cur[x];
                res[x] += freq[x];
            }
        }

        return res;
    }
};
