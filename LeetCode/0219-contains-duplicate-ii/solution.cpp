class Solution {
public:
    unordered_map<int,int>mp;
    bool containsNearbyDuplicate(vector<int>& nums, int k) { int p=0;
        for (int i=0 ; i<nums.size(); i++) {
            if(mp.count(nums[i])&&abs(mp[nums[i]]-i)<=k) return 1;
            mp[nums[i]]=i;
        }
        return 0;
    }
};
