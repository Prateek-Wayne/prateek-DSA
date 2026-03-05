class Solution {
 boolean isValid(int m, int n) {
        if (m >= 0 && n >= 0)
            return true;
        return false;
    }

    int helper(int m, int n, int[][] dp) {
        // base conditon.
        if (m == 0 && n == 0) {
            return 1;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        int left = 0;
        if (isValid(m, n - 1)) {
            left = helper(m, n - 1, dp);
        }
        int right = 0;
        if (isValid(m - 1, n)) {
            right = helper(m - 1, n, dp);
        }
        return dp[m][n] = left + right;
    }

    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            int[] temp = new int[n + 1];
            Arrays.fill(temp, -1);
            dp[i] = temp;
        }

        return helper(m - 1, n - 1, dp);
    }
}