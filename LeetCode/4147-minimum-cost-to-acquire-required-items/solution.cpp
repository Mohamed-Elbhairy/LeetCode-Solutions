class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long ans = 0;

        if (costBoth <= cost1 + cost2) {
            if (need1 == need2)
                return need1 * 1LL * costBoth;
            int mn = min(need1, need2);
            ans += costBoth * 1LL * mn;
            need1 -= mn;
            need2 -= mn;
        }
        ans += need1 * 1LL * min(costBoth,cost1);
        ans += need2 * 1LL * min(costBoth,cost2);
        return ans;
    }
};
