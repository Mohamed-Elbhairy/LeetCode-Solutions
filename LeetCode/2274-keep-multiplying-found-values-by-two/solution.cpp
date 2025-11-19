class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int freq[1001] = {};
        for (int& i : nums)
            freq[i]++;
        while (original <= 1000 && freq[original])
            original <<= 1;
        return original;
    }
};
