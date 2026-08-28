/*
 * Problem Name: Find The Prefix Common Array Of Two Arrays
 * Problem Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
 */

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> freq(n + 1), C;
        int cnt = 0;

        for (int i = 0; i < n; ++i) {

            freq[A[i]]++;
            freq[B[i]]++;

            if (A[i] == B[i]) {
                ++cnt;
            } else {
                if (freq[A[i]] == 2)
                    ++cnt;
                if (freq[B[i]] == 2)
                    ++cnt;
            }

            C.push_back(cnt);
        }

        return C;
    }
};
