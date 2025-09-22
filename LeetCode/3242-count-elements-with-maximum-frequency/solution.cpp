class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int mx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
            mx = max(mx, freq[nums[i]]);
        }
        int ans = 0;
        for (int i = 0; i <= 100; ++i) {
            freq[i] == mx ? ans++ : ans;
        }
        return ans*mx;
    }
};
