class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int sum = 0;
        for (int& i : apple) {
            sum += i;
        }
        int ans = 0;
        for (int& i : capacity) {
            if (sum == 0)
                return ans;
            ++ans;
            sum -= min(sum, i);
        }
        return ans;
    }
};
