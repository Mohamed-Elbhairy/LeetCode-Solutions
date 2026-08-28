/*
 * Problem Name: Minimum Operations To Make Array Elements Zero
 * Problem Link: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/
 */

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<long long> pow4;
        pow4.push_back(1);
        while (pow4.back() <= 1e9) {
            pow4.push_back(pow4.back() * 4LL);
        }
        long long ans = 0;
        for (auto& q : queries) {
            long long l = q[0], r = q[1];
            long long totalLevels = 0;
            for (size_t i = 0; i < pow4.size(); ++i) {
                long long p = pow4[i];
                if (p > r)
                    break;
                long long left = max(l, p);
                long long right = min(r, p * 4LL - 1);
                if (left > right)
                    continue;
                long long cnt = right - left + 1;
                int level = (int)i + 1;
                totalLevels += cnt * 1LL * level;
            }
            ans += (totalLevels + 1) / 2;
        }
        return ans;
    }
};

