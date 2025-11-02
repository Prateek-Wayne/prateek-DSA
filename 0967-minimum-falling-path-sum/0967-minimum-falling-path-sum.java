class Solution {
 boolean isValidPath(int[][] matrix, int i, int j) {
        return i >= 0 && j >= 0 && i < matrix.length && j < matrix[0].length;
    }

    int helper(int[][] matrix, int i, int j, Integer[][] dp) {
        if (!isValidPath(matrix, i, j))
            return Integer.MAX_VALUE / 2;
        if (i == 0)
            return dp[i][j] = matrix[i][j];
        if (dp[i][j] != null)
            return dp[i][j];

        int left = Integer.MAX_VALUE, up = Integer.MAX_VALUE, right = Integer.MAX_VALUE;

        if (isValidPath(matrix, i - 1, j - 1))
            left = helper(matrix, i - 1, j - 1, dp) + matrix[i][j];

        if (isValidPath(matrix, i - 1, j))
            up = helper(matrix, i - 1, j, dp) + matrix[i][j];

        if (isValidPath(matrix, i - 1, j + 1))
            right = helper(matrix, i - 1, j + 1, dp) + matrix[i][j];

        return dp[i][j] = Math.min(up, Math.min(left, right));
    }

    public int minFallingPathSum(int[][] matrix) {
        int row = matrix.length, col = matrix[0].length;
        int ans = Integer.MAX_VALUE;

        Integer[][] dp = new Integer[row][col];
        for (int i = 0; i < row; i++) {
            Integer[] temp = new Integer[col];
            Arrays.fill(temp, null);
            dp[i] = temp;
        }
        for (int j = 0; j < col; j++) {
            ans = Math.min(ans, helper(matrix, row - 1, j, dp));
        }
        return ans;
    }
}