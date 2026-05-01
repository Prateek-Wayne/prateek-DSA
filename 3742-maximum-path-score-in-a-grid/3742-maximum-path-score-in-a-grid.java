class Solution {
 int valueToSubtract(int[][] grid, int i, int j) {
        if (grid[i][j] > 0) {
            return 1;
        }
        return 0;
    }

    int helper(int[][] grid, int i, int j, int k, int[][][] dp) {
        int m = grid.length;
        int n = grid[0].length;
        if (k < 0)
            return Integer.MIN_VALUE;
        if (i < 0 || j < 0 || i >= m || j >= n)
            return Integer.MIN_VALUE;
        if (i == 0 && j == 0) {
            return (k >= 0) ? 0 : Integer.MIN_VALUE;
        }
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int top = helper(grid, i - 1, j, k - valueToSubtract(grid, i, j), dp);
        int left = helper(grid, i, j - 1, k - valueToSubtract(grid, i, j), dp);
        int best = Math.max(top, left);
        if (best == Integer.MIN_VALUE)
            return dp[i][j][k] = best;
        return dp[i][j][k] = grid[i][j] + Math.max(top, left);
    }

    public int maxPathScore(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] dp = new int[m + 1][n + 1][k + 1];
        for (int[][] temp : dp) {
            for (int[] temp2 : temp) {
                Arrays.fill(temp2, -1);
            }
            // Arrays.fill(temp, -1);
        }
        int ans = helper(grid, m - 1, n - 1, k, dp);
        return ans == Integer.MIN_VALUE ? -1 : ans;
    }

}