/*
 * Problem Name: Number Of Steps To Reduce A Number In Binary Representation To One
 * Problem Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
 */

class Solution {
public:
    int numSteps(string s) {
        int op = 0 ; 
        for (int i = s.length() - 1 ; i >= 0 ; ){
            if (i == 0 && s[i] == '1')
                break;
            if (s[i] == '0'){
                op++ , i--;
            }
            else{
                op++;
                while(i >= 0 && s[i] == '1' ){
                    i--,op++;
                }
                if (i >= 0 && s[i] == '0')
                    s[i] = '1';
            }
        }
        return op;
    }
};
