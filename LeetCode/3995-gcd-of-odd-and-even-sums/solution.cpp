class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a = 0;
        int b = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 1;; ++i) {
            if (i & 1 && cnt1 < n)
                a += i, ++cnt1;
            if (~i & 1 && cnt2 < n)
                b += i, ++cnt2;
            if (cnt1 == n and cnt2 == n)
                break;
        }
        return __gcd(a, b);
    }
}

;
