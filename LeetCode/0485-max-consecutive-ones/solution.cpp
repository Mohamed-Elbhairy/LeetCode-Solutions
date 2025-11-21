class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                continue;
            int j = i;
            while (j < nums.size() && nums[j])
                ++j;
            ret = max(ret, j - i);

            i = j - 1;
        }
        return ret;
    }
};
