class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> suff(nums.size());
        suff.back() = nums.back();
        for (int i = nums.size() - 2; i >= 0; --i) {
            suff[i] = min(suff[i + 1], nums[i]);
        }
        int pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pre = max(nums[i], pre);
            if (pre - suff[i] <= k)
                return i ;
        }
        return -1;
    }
};
