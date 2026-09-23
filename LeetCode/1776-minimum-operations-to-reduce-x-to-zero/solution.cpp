class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        if (pref[n] < x) return -1;
        if (pref[n] == x) return n;

        int minOps = 1e9;

        for (int i = 0; i <= n; ++i) {
            long long preSum = pref[i];
            if (preSum > x) break;

            long long targetSuff = x - preSum;
            int l = i, r = n, best_mid = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                long long suffSum = pref[n] - pref[mid]; 

                if (suffSum == targetSuff) {
                    best_mid = mid;
                    break;
                } else if (suffSum > targetSuff) {
                    l = mid + 1; 
                } else {
                    r = mid - 1; 
                }
            }

            if (best_mid != -1) {
                int ops = i + (n - best_mid);
                minOps = min(minOps, ops);
            }
        }

        return minOps == 1e9 ? -1 : minOps;
    }
};
