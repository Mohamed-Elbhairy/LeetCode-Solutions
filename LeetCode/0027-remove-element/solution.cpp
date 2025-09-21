class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      
        int cnt = 0;
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                ++cnt;
                continue;
            }
            nums[idx++] = nums[i];
        }
       

        return nums.size() - cnt;
    }
};
