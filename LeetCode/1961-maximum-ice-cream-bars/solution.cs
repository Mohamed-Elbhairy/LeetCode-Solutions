public class Solution {
    private void CountSort(int[]a){
        int N = 0 ;
        foreach(var i in a)
        {
            N = Math.Max(N,i);
        }

        var freq = new int[N+1];

        int n = a.Length;

        foreach(var i in a)
        {
            freq[i]++;
        }
        int idx = 0 ;
        for(int i= 0;i <= N;++i){
            while(freq[i]-->0){
                a[idx++] = i;
            }
        }
    }
    public int MaxIceCream(int[] costs, int coins) {
        CountSort(costs);
        for(int i =0;i<costs.Length;++i){
            if(costs[i]>coins){
                return i;
            }
            coins-=costs[i];
        }
        return costs.Length;
    }
}
