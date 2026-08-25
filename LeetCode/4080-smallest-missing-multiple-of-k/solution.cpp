class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int freq[101] = {};
        for (int i : nums)
            freq[i]++;
        int ans = k;
        while (true) {
            if (ans >100 || !freq[ans])
                return ans;
            ans += k;
        }
        return 0;
    }
};
