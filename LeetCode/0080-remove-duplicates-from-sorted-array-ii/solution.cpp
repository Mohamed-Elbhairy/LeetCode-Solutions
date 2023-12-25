class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;     
        int pointer = 2; 
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[pointer - 2]) {
                nums[pointer] = nums[i];
                pointer++;
            }
        }
        return pointer;
    }
};

