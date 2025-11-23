class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> choose (3);
        int sum = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            sum+=nums[i];
            choose[nums[i]%3].push_back(nums[i]);
        }
        for (auto& vec : choose)
            sort(vec.begin() , vec.end());
        int sub = 1e9;
        if (sum%3 == 0)
            return sum;
        if (sum%3 == 2){
            if (choose[1].size() >= 2)
                sub = (choose[1][0] + choose[1][1]);
            if (choose[2].size() >= 1)
                sub = min(sub , choose[2][0]);
        }
        else {
            if (choose[2].size() >= 2)
                sub = (choose[2][0] + choose[2][1]);
            if (choose[1].size() >= 1)
                sub = min(sub , choose[1][0]);
        }
        return sum - sub;
    }
};
