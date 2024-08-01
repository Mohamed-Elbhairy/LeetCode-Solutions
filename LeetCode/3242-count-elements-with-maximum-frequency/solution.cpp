class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       vector<int>freq(101,0);
       for(auto i:nums)freq[i]++;
       int mx=*max_element(freq.begin(),freq.end()); 
       int ans=0;
       for(auto i:nums)if(freq[i]==mx)ans++;
       return ans;
    }
};
