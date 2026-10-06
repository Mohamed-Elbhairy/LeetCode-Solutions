class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0 ;
        int ans= 0 ;
        for(char c:s){
            if(c == '(')++cnt;
            else {
                if(cnt == 0)++ans;
                else --cnt;
            }
        }
        ans += cnt;
        return ans;
    }
};
