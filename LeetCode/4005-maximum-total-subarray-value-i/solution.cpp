class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn =  1e9 , mx = 0;
        for(int &i : nums){
            mn = min (mn,i);
            mx = max(mx,i);
        }
        return (mx - mn)*1ll*k;
    }
};
