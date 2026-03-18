class Solution {
  public int countSubmatrices(int[][] grid, int k) {
        int count = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                grid[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += grid[j][i];
                if (sum <= k)
                    count++;
            }
        }
        return count;
    }
}