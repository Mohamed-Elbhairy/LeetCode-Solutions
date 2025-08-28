class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        map<int, int> mp;

        priority_queue<pair<int, int>> pq;
        for (auto& it : nums)
            mp[it]++;
        for (auto& i : mp) {
            pq.push({i.second, i.first});
        }
        while (pq.size()) {
            int cnt = k;
            stack<pair<int, int>> st;
            while (pq.size() && cnt && pq.top().first > 0) {
                --cnt;
                auto t = pq.top();
                t.first--;
                st.push(t);
                pq.pop();
            }
            while (st.size()) {
                if (st.top().first)
                    pq.push(st.top());
                st.pop();
            }
            if (cnt)
                return 0;
        }
        return true;
    }
};
