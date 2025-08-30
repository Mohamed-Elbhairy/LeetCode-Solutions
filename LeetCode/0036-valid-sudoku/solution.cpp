class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            mask = 0;
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.')
                    continue;
                int idx = (board[i][j] - '0') + 1;
                if ((mask & (1 << idx)))
                    return 0;
                mask |= 1 << idx;
            }
        }

        for (int i = 0; i < n; ++i) {
            mask = 0 ;
            for (int j = 0; j < n; ++j) {
                if (board[j][i] == '.')
                    continue;
                int idx = (board[j][i] - '0')+1;
                if ((mask & (1 << idx)))
                    return false;
                mask |= 1 << idx;
            }
        }
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                mask = 0 ;
                if (i + 3 <= n && j + 3 <= n) {
                    for (int r = i; r < i + 3; ++r) {
                        for (int c = j; c < j + 3; ++c) {
                            if (board[r][c] == '.')
                                continue;
                            int idx = (board[r][c] - '0') + 1;
                            if ((mask & (1 << idx)))
                                return false;
                            mask |= 1 << idx;
                        }
                    }
                  
                }
            }
        }
        return true;
    }
};
