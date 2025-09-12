class Solution {
public:
    bool doesAliceWin(string s) {
        int mask = 0;
        mask |= 1 << ('a' - 'a');
        mask |= 1 << ('i' - 'a');
        mask |= 1 << ('o' - 'a');
        mask |= 1 << ('u' - 'a');
        mask |= 1 << ('e' - 'a');
        for (auto& c : s) {
            if ((mask >> (c - 'a'))&1)
                return true;
        }
        return false;
    }
};
