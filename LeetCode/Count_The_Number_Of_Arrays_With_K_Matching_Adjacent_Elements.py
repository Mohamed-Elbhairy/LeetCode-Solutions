"""
Problem Name: Count The Number Of Arrays With K Matching Adjacent Elements
Problem Link: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/
"""

class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        return math.comb(n-1, k)*m*pow(m-1 , n-1-k , (MOD:= pow(10 , 9) + 7))%MOD
