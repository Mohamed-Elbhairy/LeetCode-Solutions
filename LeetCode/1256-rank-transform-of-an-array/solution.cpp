class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        for(int i : arr)mp[i] = 1;

        int st = 1;
        for(auto &it :mp){
            it.second = st++;
        }
        for(int &i :arr)i = mp[i];
        return arr;

    }
};
