/*
 * Problem Name: Kth Largest Element In An Array
 * Problem Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
 */

class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        int n = v.size();      
        priority_queue<int>pq;
        for(int i =0 ;i< n ; i++){
            pq.push(v[i]);
        }
        while(k--!=1){
            pq.pop();
        }
        return pq.top();
    }
};
