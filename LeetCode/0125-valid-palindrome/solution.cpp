class Solution {
private:
    string validate(string& s) {
        string ret;
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])||(s[i] >='0' && s[i]<='9')) {
                s[i] = tolower(s[i]);
                ret += s[i];
            }
        }
        return ret;
    }

public:
    bool isPalindrome(string s) {
        s = validate(s);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }
};
