class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        bool  coordinate[51][51];
        memset(coordinate,0,sizeof coordinate);
        for (auto& it : points) {
            coordinate[it[0]][it[1]] = 1;
        }
        int ans = 0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                bool valid = true;
                pair<short, short> A = {points[i][0], points[i][1]};
                pair<short, short> B = {points[j][0], points[j][1]};
                if (A.first <= B.first && B.second <= A.second) {
                    short x1 = A.first;
                    short x2 = B.first;
                    short y1 = B.second;
                    short y2 = A.second;
                    for (short x = x1; x <= x2; ++x) {
                        for (short y = y1; y <= y2; ++y) {
                            pair<short, short> P = {x, y};
                            if (P == A || P == B)
                                continue;
                            if (coordinate[x][y]) {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid)
                            break;
                    }
                    ans += valid ? 1 : 0;
                }
            }
        }
        return ans;
    }
};
