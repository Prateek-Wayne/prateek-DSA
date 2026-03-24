class Solution {
 public int[][] constructProductMatrix(int[][] grid) {
        int modd = 12345;
        int m = grid.length;
        int n = grid[0].length;
        long previous = 1;
        int[][] prefix = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j] = (int) (previous % modd);
                previous = (previous * grid[i][j]) % modd;
            }
        }
        long next = 1;
        int[][] suffix = new int[m][n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                suffix[i][j] = (int) next % modd;
                next = (next * grid[i][j]) % modd;
                grid[i][j] = (prefix[i][j] * suffix[i][j]) % modd;
            }
        }
        return grid;

    }
}