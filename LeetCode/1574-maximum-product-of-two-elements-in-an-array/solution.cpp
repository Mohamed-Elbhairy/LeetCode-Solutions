class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n1 = 1e9, n2 = 1e9;
        int n3 = -1e9, n4 = -1e9;
        for (auto& i : nums) {
            --i;
            if (n1 > i) {
                n2 = n1;
                n1 = i;
            } else if (n2 > i) {
                n2 = i;
            }
            if (n3 < i) {
                n4 = n3;
                n3 = i;
            } else if (n4 < i) {
                n4 = i;
            }
        }
        return max(n1 * n2, n3 * n4);
    }
};
