/*
 * Problem Name: Minimum Operations To Convert All Elements To Zero
 * Problem Link: https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/
 */

class Solution {
public:
    vector<int> fun(vector<int>& nums) {
        int n = nums.size();
        vector<int> nxt(n, n);
        stack<int> mono;
        mono.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (mono.size() && nums[mono.top()] >= nums[i])
                mono.pop();
            if (mono.size())
                nxt[i] = mono.top();
            mono.push(i);
        }
        return nxt;
    }
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> vals;
        unordered_map<int, vector<int>> freq;
        for (int i = 0; i < n; ++i) {
            if (freq[nums[i]].empty() && nums[i])
                vals.push_back(nums[i]);
            freq[nums[i]].push_back(i);
        }
        sort(vals.begin(), vals.end());
        auto nxt = fun(nums);
        for (int& i : vals) {
            auto& X = freq[i];
            if (X.empty())
                continue;
            int m = X.size();
            for (int j = 0; j < m; ++j) {
                ++ans;
                while (j + 1 < m) {
                    auto it = nxt[X[j]];
                    if (it > X[j + 1]) {
                        ++j;
                    } else
                        break;
                }
            }
        }
        return ans;
    }
};
