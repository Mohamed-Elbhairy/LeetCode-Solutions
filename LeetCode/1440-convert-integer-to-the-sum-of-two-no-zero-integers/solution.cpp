class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto has_no_zeroes = [&](int k){
            if (k == 0) return false;
            while (k > 0){
                if (k%10 == 0) return false;
                k/=10;
            }
            return true;
        };
        
        for (int i = 1; i < n; i++){
            if (has_no_zeroes(i) && has_no_zeroes(n-i)) return {i, n-i};
        }

        return {-1, -1};
    }
};
