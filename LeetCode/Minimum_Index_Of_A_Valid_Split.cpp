/*
 * Problem Name: Minimum Index Of A Valid Split
 * Problem Link: https://leetcode.com/problems/minimum-index-of-a-valid-split/
 */

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp1, mp2;
        multiset<pair<int, int>> mstP, mstS;
        for (auto& i : nums)
             mp2[i]++;
        for (auto& i : nums) {
            mstP.insert({0, i});
        }
        for (auto& i : mp2) {
            mstS.insert({i.second, i.first});
        }
        for (int i = 0; i < n - 1; i++) {
            auto it = mstP.find({mp1[nums[i]], nums[i]});
            mstP.erase(it);
            mstS.erase(mstS.find({mp2[nums[i]], nums[i]}));
            mp2[nums[i]]--;
            mp1[nums[i]]++;
            mstP.insert({mp1[nums[i]], nums[i]});
            mstS.insert({mp2[nums[i]], nums[i]});
            int LX = mstP.rbegin()->second;
            int LFreq = mstP.rbegin()->first;
            int RX = mstS.rbegin()->second;
            int RFreq = mstS.rbegin()->first;
            int SegL = (i + 1) / 2;
            int SegR = ((n - 1) - (i + 1) + 1) / 2;
            if (SegL < LFreq and SegR < RFreq) {
                if (LX == RX) {
                   return i ;
                }
            }
        }
        return -1;
    }
};
