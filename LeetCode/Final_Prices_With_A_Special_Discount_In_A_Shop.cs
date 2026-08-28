/*
 * Problem Name: Final Prices With A Special Discount In A Shop
 * Problem Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
 */

public class Solution
{
    public List<int> NextSmaller(int[] arr, int n)
    {
        var ret = new List<int> ();
        for(int i = 0; i < n; ++i)
        {
            ret.Add(-1);
        }
        var stack = new Stack<int>();
        stack.Push(n - 1);
        for(int i =n-2;i>=0; --i)
        {
            while (stack.Count > 0 && arr[stack.Peek()] > arr[i])
            {
                stack.Pop();
            }
            if (stack.Count > 0)
            {
                ret[i] = stack.Peek();
            }
            stack.Push(i);
        }
        return ret;
    }
    public int[] FinalPrices(int[] prices)
    {
        var ans = new int[prices.Length];
        var nextSmaller = NextSmaller(prices, prices.Length);
        for (int i = 0; i < prices.Length; ++i)
        {
            ans[i] = prices[i] - (nextSmaller[i] == -1 ? 0 : prices[nextSmaller[i]]);
        }
        return ans;
    }
}
