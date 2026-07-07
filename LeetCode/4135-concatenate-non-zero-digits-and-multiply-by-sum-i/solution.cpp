class Solution {
public:
    pair<int,int> reBuild(int X){
        int ret = 0 ,cnt = 0;
        while(X){
            int d = X % 10;
            if(d){
                ret = ret*10 + d;
            }
            cnt += d;
            X/=10;
        }
        return {ret,cnt};
    }
    long long sumAndMultiply(int n) {
        auto ret = reBuild(n);
        long long cnt = ret.second;
        ret = reBuild(ret.first);
        return ret.first*1ll*cnt;
    }
};
