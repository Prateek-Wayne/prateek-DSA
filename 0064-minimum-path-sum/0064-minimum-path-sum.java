class Solution {
      public int helper(int[][] grid, int m, int n, int[][] dp) {
        if (m < 0 || n < 0)
            return Integer.MAX_VALUE;
        if (m == 0 && n == 0) {
            return grid[m][n];
        }
        if (dp[m][n] != -1)
            return dp[m][n];
        int left = helper(grid, m, n - 1, dp);
        int top = helper(grid, m - 1, n, dp);
        return dp[m][n] = grid[m][n] + Math.min(left, top);
    }

    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
         int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            int[] temp = new int[n];
            Arrays.fill(temp, -1);
            dp[i] = temp;
        }
        return helper(grid, m - 1, n - 1, dp);
    }
}