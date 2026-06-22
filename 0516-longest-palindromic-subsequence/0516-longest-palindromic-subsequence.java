class Solution {
    public int longestPalindromeSubseq(String s) {
        String p = "";
        int index = s.length();
        for (int i = index - 1; i >= 0; i--) {
            p += s.charAt(i);
        }
        int[][] dp = new int[index + 1][index + 1];
        for (int i = 1; i <= index; i++) {
            for (int j = 1; j <= index; j++) {
                if (s.charAt(i-1) == p.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[index][index];
    }
}