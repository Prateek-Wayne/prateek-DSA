class Solution {
    int helper(int[][] obstacleGrid, int m, int n, int[][] dp) {
        if (m == 0 && n == 0) {
            if (obstacleGrid[m][n] != 1)
                return 1;
            return 0;
        }
        if (dp[m][n] != -1)
            return dp[m][n];
        // left...
        int left = 0;
        if (n > 0) {
            if (obstacleGrid[m][n - 1] != 1) {
                left = helper(obstacleGrid, m, n - 1, dp);
            }
        }
        // right...
        int right = 0;
        if (m > 0) {
            if (obstacleGrid[m - 1][n] != 1) {
                right = helper(obstacleGrid, m - 1, n, dp);
            }
        }
        return dp[m][n] = left + right;
    }

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            int[] temp = new int[n];
            Arrays.fill(temp, -1);
            dp[i] = temp;
        }
        return helper(obstacleGrid, m - 1, n - 1, dp);
    }
}