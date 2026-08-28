/*
 * Problem Name: Minimum Number Of People To Teach
 * Problem Link: https://leetcode.com/problems/minimum-number-of-people-to-teach/
 */

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<int> language_freq(n+1);
        vector<bool> vis(languages.size()+1);
        int sum = 0;
        for (int i = 0 ; i < languages.size() ; i++){
            sort(languages[i].begin() , languages[i].end());
        }
        for (int i = 0 ; i < friendships.size() ; i++){
            int first = friendships[i][0]-1 , second = friendships[i][1]-1;
            bool flag = 0;
            for (int j = 0 , k = 0 ; j <  languages[first].size() && k < languages[second].size();){
                if (languages[first][j] == languages[second][k]){
                    flag = 1;
                    break;
                }
                else if (languages[first][j] < languages[second][k] )
                    j++;
                else 
                    k++;
            }
            if (!flag){
                if (!vis[first]){
                    for (auto& language : languages[first])
                        language_freq[language]++;
                    sum++;
                    vis[first] = 1;
                }
                if (!vis[second]){
                    for (auto& language : languages[second])
                        language_freq[language]++;
                    sum++;
                    vis[second] = 1;
                }
            }
        }
        int mx = *max_element(language_freq.begin() , language_freq.end());
        return sum - mx;
    }
};
