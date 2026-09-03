class Solution {
    bool canparity(vector<int>& v, int& mn) {
        bool odd = true, even = true;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] % 2 == 1) {
                if (v[i] - mn < 1)
                    even = false;
            } else {
                if (v[i] - mn < 1)
                    odd = false;
            }
        }
        return odd || even;
    }

public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mn = 1e9 + 1;
        for (int i = 0; i < n; ++i) {
            if (nums1[i] % 2)
                mn = min(mn, nums1[i]);
        }
        return canparity(nums1, mn);
    }
};
