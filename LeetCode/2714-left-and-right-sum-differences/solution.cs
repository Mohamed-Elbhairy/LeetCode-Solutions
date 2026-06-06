public class Solution
{
    public int[] LeftRightDifference(int[] nums)
    {

        var LeftSum = new int[nums.Length];
        var RightSum = new int[nums.Length];
        var Res = new int[nums.Length];

        for(int i = 1; i < nums.Length; i++)
        {
            LeftSum[i] = nums[i - 1] + LeftSum[i - 1];
        }
        for(int i = nums.Length - 2; i >= 0; --i)
        {
            RightSum[i] = nums[i + 1] + RightSum[i + 1];
        }
        for(int i = 0; i < nums.Length; ++i)
        {
            Res[i] = Math.Abs(LeftSum[i] - RightSum[i]);
        }
        return Res;

    }
}
