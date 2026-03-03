class Solution {
public static int minSwaps(int[][] grid) {
        int n = grid.length;
        int[] zeroes = new int[n];
        for (int i = 0; i < n; i++) {
            int countOfZeroes = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    countOfZeroes++;
                } else {
                    break;
                }
            }
            zeroes[i] = countOfZeroes;
        }
        int steps = 0;
        for (int i = 0; i < zeroes.length; i++) {
            int requiredZeros = n - i - 1;
            if (zeroes[i] >= requiredZeros)
                continue;
            int j = i + 1;
            for (; j < n; j++) {
                if (zeroes[j] >= requiredZeros) {
                    break;
                }
            }
            if (j == n)
                return -1;
            steps += (j - i);
            // Replace the swap section with:
            while (j > i) {
                int temp = zeroes[j];
                zeroes[j] = zeroes[j - 1];
                zeroes[j - 1] = temp;
                j--;
            }
        }
        return steps;
    }
}