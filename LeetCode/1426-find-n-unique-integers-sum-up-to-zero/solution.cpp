class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        long long sum = 0;
        for (int i = 1; i < n; ++i)
            ret.push_back(i), sum += i;
        ret.push_back(-sum);
        return ret;
    }
};
