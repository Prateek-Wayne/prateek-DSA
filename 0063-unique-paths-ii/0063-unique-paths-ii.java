class Solution {

    boolean isValidPath(int i, int j, int[][] obstacleGrid) {
        if (i >= 0 && j >= 0) {
            if (obstacleGrid[i][j] != 1)
                return true;
        }
        return false;
    }

    int helper(int[][] obstacleGrid, int i, int j, int[][] dp) {
        if(!isValidPath(i,j,obstacleGrid))
            return 0;
        if (i == 0 && j == 0) {
            if (isValidPath(i, j, obstacleGrid))
                return 1;
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = 0;
        if (isValidPath(i, j, obstacleGrid)) {
            left = helper(obstacleGrid, i - 1, j, dp);
        }
        int up = 0;
        if (isValidPath(i, j, obstacleGrid)) {
            up = helper(obstacleGrid, i, j - 1, dp);
        }
            return dp[i][j] = left + up; 
    }

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int i = obstacleGrid.length;
        int j = obstacleGrid[0].length;
        int[][] dp = new int[i][j];
        for (int x = 0; x < i; x++) {
            int[] temp = new int[j];
            Arrays.fill(temp, -1);
            dp[x] = temp;
        }
        return helper(obstacleGrid, i - 1, j - 1, dp);
    }
}