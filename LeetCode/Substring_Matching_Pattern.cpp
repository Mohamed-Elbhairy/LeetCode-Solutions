/*
 * Problem Name: Substring Matching Pattern
 * Problem Link: https://leetcode.com/problems/substring-matching-pattern/
 */

class Solution {
public:
    bool hasMatch(string s, string p) {
        int idx= p.find('*');
        string pre = p.substr(0,idx);
        string suff = p.substr(idx+1);
        for(int i =0;i+pre.size()<=s.size();i++){
            if(s.substr(i,pre.size())==pre){
                if(s.find(suff, i+pre.size())!=-1)return true;
            }
        }
        return 0;
    }
};
