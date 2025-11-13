class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 0;
        int cur = 10;
        rem = 1 % k;
        if (rem == 0)
            return 1;
        if(k%2 == 0)
            return -1;
        for (int i = 2; i <= k; ++i) {
            rem = (cur + rem) % k;
            cur *= 10;
            cur %= k;
            if (rem == 0)
                return i;
        }
        return -1;
    }
};
