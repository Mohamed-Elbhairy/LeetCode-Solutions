class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 3, 0);
        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
        }
        vector<int> ret;
        for (int i = 0; i <= n + 2; ++i) {
            while (freq[i] > 1)
                ret.push_back(i), freq[i]--;
        }
        return ret ;
    }
};
