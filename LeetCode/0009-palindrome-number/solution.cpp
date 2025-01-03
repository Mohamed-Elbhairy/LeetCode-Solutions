class Solution {
public:
    bool isPalindrome(int x) {
        int temp =x;
        long long reversed = 0 ;
        while(temp){
            reversed*=10;
            reversed+=temp%10;
            temp/=10;
        }
        return x>=0 and x==reversed;
    }
};
