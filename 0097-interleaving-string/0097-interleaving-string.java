class Solution {

    boolean helper(String s1, String s2, String s3, int i, int j, int k, Boolean[][][] dp) {

        int m = s1.length();
        int n = s2.length();
        int o = s3.length();

        if (i == m && j == n && k == o)
            return true;
        if (dp[i][j][k] != null)
            return dp[i][j][k];
        if (i < m && j < n && k < o && s3.charAt(k) == s1.charAt(i) && s3.charAt(k) == s2.charAt(j)) {
            return dp[i][j][k] = helper(s1, s2, s3, i + 1, j, k + 1, dp) || helper(s1, s2, s3, i, j + 1, k + 1, dp);
        } else if (k < o && i < m && s3.charAt(k) == s1.charAt(i)) {
            return dp[i][j][k] = helper(s1, s2, s3, i + 1, j, k + 1, dp);
        } else if (k < o && j < n && s3.charAt(k) == s2.charAt(j)) {
            return dp[i][j][k] = helper(s1, s2, s3, i, j + 1, k + 1, dp);
        } else
            return dp[i][j][k] = false;
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        int m = s1.length();
        int n = s2.length();
        int o = s3.length();
        Boolean[][][] dp = new Boolean[m+1][n+1][o+1];
        return helper(s1, s2, s3, 0, 0, 0, dp);
    }
}