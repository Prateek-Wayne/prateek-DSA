class Solution {
 static int helperTop(int[][] grid, int r1, int c1, int r2, int c2, int[][][][] dp) {
        if (r1 < 0 || r2 < 0 || c1 < 0 || c2 < 0)
            return Integer.MIN_VALUE;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return Integer.MIN_VALUE;
        int q1 = grid[r1][c1];
        int q2 = grid[r2][c2];
        int cherries = 0;
        if (dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];
        if (r1 == r2 && c1 == c2) {
            cherries = q1;
            if ((r1 == 0 && c1 == 0) || (r2 == 0 && c2 == 0)) {
                return dp[r1][c1][r2][c2] = cherries;
            }
            grid[r1][c1] = 0;
        } else {
            cherries = q1 + q2;
            grid[r1][c1] = 0;
            grid[r2][c2] = 0;
        }
        int p1 = helperTop(grid, r1, c1 - 1, r2, c2 - 1, dp);
        int p2 = helperTop(grid, r1 - 1, c1, r2 - 1, c2, dp);
        int p3 = helperTop(grid, r1, c1 - 1, r2 - 1, c2, dp);
        int p4 = helperTop(grid, r1 - 1, c1, r2, c2 - 1, dp);
        grid[r1][c1] = q1;
        grid[r2][c2] = q2;
        return dp[r1][c1][r2][c2] = cherries + Math.max(Math.max(p1, p2), Math.max(p3, p4));
    }

    public static int cherryPickup(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] == -1 || grid[n - 1][n - 1] == -1)
            return 0;
        int[][][][] dp = new int[n + 1][n + 1][n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            int[][][] temp = new int[n + 1][n + 1][n + 1];
            for (int j = 0; j <= n; j++) {
                int[][] temp2 = new int[n + 1][n + 1];
                for (int k = 0; k <= n; k++) {
                    int[] temp3 = new int[n + 1];
                    Arrays.fill(temp3, -1);
                    temp2[k] = temp3;
                }
                temp[j] = temp2;
            }
            dp[i] = temp;
        }
        int ans = helperTop(grid, n - 1, n - 1, n - 1, n - 1, dp);
        if (ans < 0)
            return 0;
        return ans;
    }
}