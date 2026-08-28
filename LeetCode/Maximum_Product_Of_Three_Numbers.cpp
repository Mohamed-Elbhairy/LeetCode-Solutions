/*
 * Problem Name: Maximum Product Of Three Numbers
 * Problem Link: https://leetcode.com/problems/maximum-product-of-three-numbers/
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n1 = -1e9, n2 = -1e9, n3 = -1e9;
        for (int i : nums) {
            if (i > n1) {
                n3 = n2;
                n2 = n1;
                n1 = i;
            } else if (i > n2) {
                n3 = n2;
                n2 = i;
            } else if (i > n3) {
                n3 = i;
            }
        }
        long long ans = 1ll * n1 * n2 * n3;
        n3 = n1;
        n1 = 1e9, n2 = 1e9;
        for (int i : nums) {
            if (i < n1) {
                n2 = n1;
                n1 = i;
            } else if (i < n2) {
                n2 = i;
            } 
        }
        ans = max(ans,1ll*n1*n2*n3);
        return ans;
    }
};
