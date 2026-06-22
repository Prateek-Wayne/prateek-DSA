class Solution {
      public int longestCommonSubsequence(String text1, String text2) {
        int index1 = text1.length();
        int index2 = text2.length();
        int[][] dp = new int[index1 + 1][index2 + 1];
        for (int[] temp : dp)
            Arrays.fill(temp, 0);
        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[index1][index2];
    }
}