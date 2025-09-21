class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ret = l;
        if (nums.front() > target)
            return 0;
        if (nums.back() < target)
            return nums.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
                ret = mid;
            } else
                l = mid + 1;
        }
        return ret;
    }
};
