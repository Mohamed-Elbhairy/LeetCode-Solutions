class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt = 1, cnt1 = 1;
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                ++cnt;
            else
                cnt = 1;
            if (nums[i] < nums[i - 1])
                ++cnt1;
            else
                cnt1 = 1;
            ans = max(ans, cnt);
            ans = max(ans, cnt1);
        }
        return ans;
    }
};
