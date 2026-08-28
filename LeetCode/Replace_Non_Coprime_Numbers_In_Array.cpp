/*
 * Problem Name: Replace Non Coprime Numbers In Array
 * Problem Link: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
 */

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st; 
        st.push(nums[0]);
        for (int i = 1 ; i < nums.size() ; i++){
            int other = nums[i];
            int g = __gcd(st.top() , other);
            while (g > 1 && !st.empty() ){
                other = (st.top()* 1LL * other) / g ; 
                st.pop();
                if (!st.empty())
                    g = __gcd(other , st.top());
            }
            st.push(other);
        }
        vector<int> ans;
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
