/*
 * Problem Name: Find X Sum Of All K Long Subarrays Ii
 * Problem Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/
 */

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ret;
        set<pair<int, int>> taken;
        set<pair<int, int>, greater<pair<int, int>>> rem;
        map<int, int> freq;
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            freq[nums[i]]++;
        }
        for (auto& it : freq) {
            rem.insert({it.second, it.first});
        }
        while (taken.size() < x && rem.size()) {
            auto tp = *rem.begin();
            ans += 1ll * tp.first * tp.second;
            taken.insert(tp);
            rem.erase(rem.begin());
        }
        ret = {ans};
        for (int i = k; i < n; ++i) {
            if (nums[i] == nums[i - k]) {
                ret.push_back(ans);
                continue;
            }
            int cnt1 = freq[nums[i - k]];
            auto it1 = rem.find({cnt1, nums[i - k]});
            if (it1 != rem.end()) {
                rem.erase(it1);
            }
            it1 = taken.find({cnt1, nums[i - k]});
            if (it1 != taken.end()) {
                ans -= 1ll * cnt1 * nums[i - k];
                taken.erase(it1);
            }
            freq[nums[i - k]]--;
            rem.insert({ freq[nums[i - k]],nums[i - k] });
            int cnt = freq[nums[i]];
            auto it = rem.find({cnt, nums[i]});
            if (it != rem.end()) {
                rem.erase(it);
            }
            it = taken.find({cnt, nums[i]});
            if (it != taken.end()) {
                ans -= 1ll * cnt * nums[i];
                taken.erase(it);
            }

            if (taken.size()) {
                rem.insert(*taken.begin());
                ans -=1ll*taken.begin()->first * taken.begin()->second;
                taken.erase(taken.begin());
            }
            rem.insert({cnt + 1, nums[i]});
            freq[nums[i]]++;
            while (taken.size() < x && rem.size()) {
                auto tp = *rem.begin();
                ans += 1ll*tp.first * tp.second;
                taken.insert(tp);
                rem.erase(rem.begin());
            }
            ret.push_back(ans);
        }
        return ret;
    }
};
