class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int ans = 0;
        int ones = 0, zeros = 0;
        while (r < nums.size()) {

            if (nums[r])
                ones++;
            else
                zeros++;

            while (zeros > 1) {
                if (nums[l])
                    --ones;
                else
                    --zeros;
                ++l;
            }

            ans = max(ones, ans);

            ++r;
        }
        if (ans == nums.size())
            --ans;
        return ans;
    }
};
