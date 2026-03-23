class Pair {
    long min;
    long max;

    Pair(long min, long max) {
        this.min = min;
        this.max = max;
    }
}

class Solution {
  
    Pair helper(int[][] grid, int i, int j, Pair[][] dp) {

        if (i == 0 && j == 0)
            return new Pair(grid[i][j], grid[i][j]);

        if (dp[i][j] != null)
            return dp[i][j];

        long minVal = Long.MAX_VALUE;
        long maxVal = Long.MIN_VALUE;

        if (j > 0) {
            Pair left = helper(grid, i, j - 1, dp);
            long a = grid[i][j] * left.min;
            long b = grid[i][j] * left.max;
            minVal = Math.min(minVal, Math.min(a, b));
            maxVal = Math.max(maxVal, Math.max(a, b));
        }

        if (i > 0) {
            Pair top = helper(grid, i - 1, j, dp);
            long a = grid[i][j] * top.min;
            long b = grid[i][j] * top.max;
            minVal = Math.min(minVal, Math.min(a, b));
            maxVal = Math.max(maxVal, Math.max(a, b));
        }

        return dp[i][j] = new Pair(minVal, maxVal);
    }

    public int maxProductPath(int[][] grid) {
        int m = grid.length, n = grid[0].length;

        Pair[][] dp = new Pair[m][n];

        Pair ans = helper(grid, m - 1, n - 1, dp);

        if (ans.max < 0) return -1;

        return (int)(ans.max % 1000000007);
    }
}