class Solution {
public:
    double GetRatio(int a, int b) { return (double)a / b; }
    double Get(int a, int b) {
        return (double)(a + 1) / (b + 1) - (double)a / b;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();
        for (int i = 0; i < n; ++i) {
            pq.push({Get(classes[i][0], classes[i][1]), i});
        }
        while (extraStudents--) {
            auto p = pq.top();
            pq.pop();
            int idx = p.second;
            classes[idx][0]++;
            classes[idx][1]++;
            pq.push({Get(classes[idx][0], classes[idx][1]), idx});
        }
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += GetRatio(classes[i][0], classes[i][1]) / n;
        }
        return ans;
    }
};

