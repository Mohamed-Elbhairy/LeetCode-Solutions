/*
 * Problem Name: 2212. Removing Minimum And Maximum From Array
 * Problem Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
 */

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int n = nums.size();
        int mxPos = 0, mnPos = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[mxPos]){
                mxPos = i;
            }
            if (nums[i] < nums[mnPos]){
                mnPos = i;
            }
        }
        int mn = min(mnPos,mxPos);
        int mx = max(mnPos,mxPos);
        --n;
        return min({n-mn+1 , mx+1 , (n-mx+1) + (mn+1)});
    }
};
