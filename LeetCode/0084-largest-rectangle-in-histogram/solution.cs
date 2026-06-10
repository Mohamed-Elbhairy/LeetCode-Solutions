public class Solution {
    public int LargestRectangleArea(int[] heights) {
        Span<int> stack = stackalloc int[heights.Length];
        int currentArea, n=heights.Length;
        int maxArea = 0, top = -1, temp;

        for (int i = 0; i < heights.Length; i++)
        {
            while (top >= 0 && heights[stack[top]] >= heights[i])
            {
                temp = stack[top--];
                int width = top < 0 ? i : i - stack[top] - 1;
                currentArea = heights[temp] * width;
                if (maxArea < currentArea)
                    maxArea = currentArea;
            }
            stack[++top] = i;
        }
         while (top >= 0)
        {
            temp = stack[top--];
            currentArea = heights[temp] * (top < 0 ? n : n - stack[top] - 1);
            if (maxArea < currentArea) maxArea = currentArea;
        }
        return maxArea;
    
    }
}
