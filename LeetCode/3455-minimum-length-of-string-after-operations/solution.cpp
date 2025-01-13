class Solution {
public:
    int minimumLength(string s) {
        int freq[26]={};
        for(auto&i:s)freq[i-'a']++;
        int ans = 0;
        for(auto &i:freq){
            while(i>=3)i-=2;
            ans+=i;         
        }
        return ans ;
    }
};
