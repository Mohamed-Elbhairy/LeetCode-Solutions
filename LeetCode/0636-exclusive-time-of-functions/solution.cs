public class Solution
{

    
    public int[] ExclusiveTime(int n, IList<string> logs)
    {
        var ans = new int[n];
        var stack = new Stack<int>();

        int prevTime = 0;

        foreach (var log in logs)
        {
            var parts = log.Split(':');

            int id = int.Parse(parts[0]);
            bool isStart = parts[1] == "start";
            int time = int.Parse(parts[2]);

            if (isStart)
            {
                if (stack.Count > 0)
                {
                    ans[stack.Peek()] += time - prevTime;
                }

                stack.Push(id);
                prevTime = time;
            }
            else
            {
                ans[stack.Pop()] += time - prevTime + 1;
                prevTime = time + 1;
            }

        }
        return ans;

    }
}
