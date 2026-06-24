public class Solution {
    private int MOD = 1_000_000_007;

    public int ZigZagArrays(int n, int l, int r) {
        int m = r - l;   
        if (m == 1) return 2;
        int[] vector = new int[m];
        Array.Fill(vector, 1);
        /*                  0 0 0 0 1
                            0 0 0 1 1
        for m = 5, matrix = 0 0 1 1 1
                            0 1 1 1 1
                            1 1 1 1 1*/      
        int[,] matrix = new int[m, m];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = m - 1 - i; j < m; j++) {
                matrix[i, j] = 1;
            } 
        }

        n--;
        while (n >= 1) {
            if (n % 2 == 1) {
                vector = VetXMat(vector, matrix);
            }
            matrix = MatSquare(matrix);
            n /= 2;
        }

        int result = 0;
        for (int i = 0; i < m; i++) {
            result = (result + vector[i]) % MOD;
        }
        return (result * 2) % MOD;
    }

    private int[] VetXMat(int[] vector, int[,] matrix) {
        int size = vector.Length;
        int[] result = new int[size];

        for (int i = 0; i < size; i++) {
            long sum = 0;
            for (int j = 0; j < size; j++) { 
                sum += ((long)vector[j] * matrix[i, j]) % MOD;
            }
            result[i] = (int)(sum % MOD);
        }
        return result;
    }

    private int[,] MatSquare(int[,] matrix) {
        int size = matrix.GetLength(0);
        int[,] result = new int[size, size];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                long sum = 0;
                for (int k = 0; k < size; k++) {
                    sum += ((long)matrix[i, k] * matrix[k, j]) % MOD;
                }
                result[i, j] = (int)(sum % MOD);
            }
        }
        return result;
    }
}
