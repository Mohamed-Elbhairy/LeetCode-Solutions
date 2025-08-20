class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstMaximum = INT_MAX, secondMaximum = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= firstMaximum)
                firstMaximum = nums[i];
            else if (nums[i] <= secondMaximum)
                secondMaximum = nums[i];
            else {

                return true;
            }
        }
        return false;
    }
};
