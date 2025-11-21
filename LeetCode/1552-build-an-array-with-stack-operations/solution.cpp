class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 1;
        vector<string> ans;
        for (int i = 0; i < target.size(); ++i) {
            while (cur < target[i]) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++cur;
            }
            ans.push_back("Push");
            ++cur;
        }
        return ans;
    }
};
