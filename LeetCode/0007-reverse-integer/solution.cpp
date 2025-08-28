class Solution {
public:
    int reverse(int x) {
        int ret = 0 ; 
        bool neg = x<0 ; 
        if(neg &&  x == INT_MIN)return 0 ;
        if(neg)x*=-1;

        while(x){
            if(ret*10LL+x%10>INT_MAX){
                return 0 ; 
            }
            ret*=10;
            ret +=x%10 ;
            x/=10; 
        }   
        if(neg)ret*=-1;
        return ret ;
    }
};
