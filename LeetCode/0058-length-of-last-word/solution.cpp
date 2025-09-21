class Solution {
public:
    int lengthOfLastWord(string s) {
       
        while( s.size() && s.back()==' ')s.pop_back();
        for(int i = s.size()-1 ; i>=0 ;--i){
            if(s[i] == ' ')return s.size() - i - 1 ;
        }
        return s.size();
    }
};
