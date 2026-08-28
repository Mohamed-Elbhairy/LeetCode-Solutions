/*
 * Problem Name: Kth Largest Element In A Stream
 * Problem Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
 */

public class OrderStatisticTree
{
    private class Node
    {
        public int Value;
        public int Size;
        public Node Left;
        public Node Right;

        public Node(int value)
        {
            Value = value;
            Size = 1;
        }
    }

    private Node root;

    private int GetSize(Node node)
    {
        return node?.Size ?? 0;
    }

    public void Insert(int value)
    {
        root = Insert(root, value);
    }

    private Node Insert(Node node, int value)
    {
        if (node == null)
            return new Node(value);

        if (value < node.Value)
            node.Left = Insert(node.Left, value);
        else
            node.Right = Insert(node.Right, value);

        node.Size = 1 + GetSize(node.Left) + GetSize(node.Right);

        return node;
    }

    public int KthGreatest(int k)
    {
        if (k <= 0 || k > GetSize(root))
            throw new ArgumentOutOfRangeException();

        return KthGreatest(root, k);
    }

    private int KthGreatest(Node node, int k)
    {
        int rightSize = GetSize(node.Right);

        if (rightSize + 1 == k)
            return node.Value;

        if (k <= rightSize)
            return KthGreatest(node.Right, k);

        return KthGreatest(node.Left, k - rightSize - 1);
    }
}
public class KthLargest
{
    private readonly OrderStatisticTree bt = new();
    private int _k;
    public KthLargest(int k, int[] nums)
    {
        _k = k;
        foreach(var n in nums)
        {
            bt.Insert(n);
        }
    }

    public int Add(int val)
    {

        bt.Insert(val);
        return bt.KthGreatest(_k);
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.Add(val);
 */
