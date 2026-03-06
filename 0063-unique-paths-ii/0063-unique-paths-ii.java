class Solution {

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;

        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                } else if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                int left = 0;
                if (j > 0) {
                    left = dp[i][j - 1];
                }
                int right = 0;
                if (i > 0) {
                    right = dp[i - 1][j];
                }
                dp[i][j] = left + right;
            }
        }
        return dp[m - 1][n - 1];
    }
}