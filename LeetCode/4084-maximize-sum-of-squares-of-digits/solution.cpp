class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ret = "";
        while (ret.size() < num) {
            int x = min(9, sum);
            ret += char('0' + x);
            sum -= x;
        }
        if(sum)return "";
        return ret;
    }
};
