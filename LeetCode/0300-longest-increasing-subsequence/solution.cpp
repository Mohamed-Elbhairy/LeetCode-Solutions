class Solution {
public:
    int n;
    vector<int> v;
    vector<vector<int>> dp;
    int rec(int idx, int val) {
        // base case
        if (idx == n)
            return 0;
        int& ret = dp[idx][val+1];
        if (~ret)
            return ret;
        int ch1 = -1e5;
        int ch2 = rec(idx + 1, val);
        if (val == -1 || v[idx] > v[val])
            ch1 = rec(idx + 1, idx)+1;
        return ret = max(ch1, ch2);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp = vector<vector<int>>(nums.size(), vector<int>(nums.size()+1, -1));
        v = nums;
        return rec(0, -1);
    }
};
