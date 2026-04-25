class Solution {
   public String longestPalindrome(String s) {
        int m = s.length();
        String p = "";
        for (int i = m - 1; i >= 0; i--) {
            p += s.charAt(i);
        }
        int[][] dp = new int[m + 1][m + 1];

        int maxLen = 0, endIdx = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (s.charAt(i - 1) == p.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    // validity check: ensures it's actually a palindrome
                    if (dp[i][j] > maxLen && i + j == m + dp[i][j]) {
                        maxLen = dp[i][j];
                        endIdx = i;
                    }
                }
            }
        }
        return s.substring(endIdx - maxLen, endIdx);

    }
}