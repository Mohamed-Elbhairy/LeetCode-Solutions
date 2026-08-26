class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long num1 = LLONG_MAX;
        long long num2 = LLONG_MAX;
        for (int i : nums) {
            if (i <= num1)
                num1 = i;
            else if (i <= num2)
                num2 = i;
            else if(i > num2 && num2 > num1)
                return true;
           
        }
        return false;
    }
};
