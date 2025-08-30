class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)return 0 ; 
        if(x == 1)return 1 ; 
        int l = 0 , r = x , ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(mid*1LL*mid<=x)l = mid+1,ans = mid ;
            else r = mid-1;
        }
        return ans ; 
    }
};
