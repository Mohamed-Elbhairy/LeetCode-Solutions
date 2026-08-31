class Solution {
public:
    bool detectCapitalUse(string word) {
        bool isall = true;
        for (int i = 1; i < word.size(); ++i) {
            if (isupper(word[0]) != isupper(word[i]))
                isall = false;
        }
        if (isall)
            return true;
        if (isupper(word[0])) {
            for (int i = 1; i < word.size(); ++i) {
                if (isupper(word[0]) == isupper(word[i]))
                    return false;
            }
            return true;
        }
        return false;
    }
};
