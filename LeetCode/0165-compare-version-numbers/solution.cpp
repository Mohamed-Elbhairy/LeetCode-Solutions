class Solution {
    vector<int> getParts(string& version1, int& parts) {
        vector<int> v(parts+1);
        int idx = 0;
        for (int i = 0; i < version1.size(); ++i) {
            int X = 0;
            while (i < version1.size() && version1[i] != '.') {
                X *= 10;
                X += version1[i] - '0';
                ++i;
            }
            v[idx++] = X;
        }
        return v;
    }

public:
    int compareVersion(string version1, string version2) {
        int parts = max(count(version1.begin(), version1.end(), '.'),
                        count(version2.begin(), version2.end(), '.'));
        auto A = getParts(version1, parts);
        auto B = getParts(version2, parts);
        if (A == B)
            return 0;
        if (A < B)
            return -1;
        return 1;
    }
};
