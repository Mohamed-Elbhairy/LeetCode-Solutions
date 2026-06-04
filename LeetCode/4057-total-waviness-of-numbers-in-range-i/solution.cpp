class Solution {
private:
    int countValid(string& cur) {
        int ret = 0;
        for (int i = 1; i < cur.size() - 1; ++i) {
            if ((cur[i] > cur[i - 1] && cur[i] > cur[i + 1]) ||
                (cur[i] < cur[i - 1] && cur[i] < cur[i + 1]))
                ++ret;
        }
        return ret;
    }

public:
    int totalWaviness(int num1, int num2) {
        int ret = 0;
        while (num1 <= num2) {
            auto cur = to_string(num1);

            ret += countValid(cur);
            
            ++num1;
        }
        return ret;
    }
};
