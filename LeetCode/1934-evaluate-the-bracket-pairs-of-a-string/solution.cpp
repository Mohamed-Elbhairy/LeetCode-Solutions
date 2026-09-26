class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;
        string ret = "";

        for (auto& KeyVal : knowledge) {
            mp[KeyVal.front()] = KeyVal.back();
        }

        string curKey = "";
        bool inBracket = 0;

        for (auto& c : s) {
            if (isalpha(c)) {
                if (inBracket) {
                    curKey += c;
                } else {
                    ret += c;
                }
            } else {
                if (c == '(') {
                    inBracket = true;
                } else {
                    auto X = mp.count(curKey) ? mp[curKey] : "?";
                    ret += X;
                    curKey.clear();
                    inBracket = false;
                }
            }
        }
        return ret;
    }
};
