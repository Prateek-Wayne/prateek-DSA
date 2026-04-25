class Solution {
 int helper(String text1, String text2, int i, int j, int[][] dp) {
        if (i == 0 || j == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1.charAt(i - 1) == text2.charAt(j - 1))
            return dp[i][j] = 1 + helper(text1, text2, i - 1, j - 1, dp);
        else {
            return dp[i][j] = Math.max(helper(text1, text2, i - 1, j, dp), helper(text1, text2, i, j - 1, dp));
        }
    }

    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            int[] temp = new int[n + 1];
            Arrays.fill(temp, -1);
            dp[i] = temp;
        }
        return helper(text1, text2, m, n, dp);
    }
}