/*
 * Problem Name: Total Waviness Of Numbers In Range I
 * Problem Link: https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
 */

public class Solution
{
    private int CountWavyPositions(string s)
    {
        int count = 0;

        for (int i = 1; i < s.Length - 1; i++)
        {
            bool isPeak =
                s[i] > s[i - 1] &&
                s[i] > s[i + 1];

            bool isValley =
                s[i] < s[i - 1] &&
                s[i] < s[i + 1];

            if (isPeak || isValley)
                count++;
        }

        return count;
    }

    public int TotalWaviness(int num1, int num2)
    {
        int total = 0;

        for (int num = num1; num <= num2; num++)
        {
            string s = num.ToString();
            total += CountWavyPositions(s);
        }

        return total;
    }
}
