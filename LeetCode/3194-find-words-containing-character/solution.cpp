class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char& x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); ++i) {
            bool Good = false;
            for (int j = 0; j < words[i].size(); ++j) {
                if (words[i][j] == x) {
                    Good = true;
                    break;
                }
            }
            if (Good)
                ans.push_back(i);
        }
        return ans;
    }
};
