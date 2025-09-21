class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool freq[100 * 2 + 1] = {};
        int Shift = 100;
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!freq[nums[i] + Shift])
                ++k;
            freq[nums[i] + Shift] = true;
        }
        int idx = 0;
        for(int i =-100;i<=100;++i){
            if(freq[i+Shift])nums[idx] = i , ++idx ; 
        }
        return k;
    }
};
