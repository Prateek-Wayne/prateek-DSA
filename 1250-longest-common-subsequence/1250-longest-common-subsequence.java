class Solution {
    int helper(String text1, String text2, int index1, int index2, Integer[][] dp) {
        if (index1 == 0 || index2 == 0)
            return 0;
        if (dp[index1][index2] != null)
            return dp[index1][index2];

        if (text1.charAt(index1-1) == text2.charAt(index2-1))
            return dp[index1][index2] = 1 + helper(text1, text2, index1 - 1, index2 - 1, dp);
        else {
            return dp[index1][index2] = 0 + Math.max(helper(text1, text2, index1 - 1, index2, dp),
                    helper(text1, text2, index1, index2 - 1, dp));
        }
    }

    public int longestCommonSubsequence(String text1, String text2) {
        int index1 = text1.length();
        int index2 = text2.length();
        Integer[][] dp = new Integer[index1 + 1][index2 + 1];
        for (int i = 0; i <= index1; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= index2; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1))
                     dp[i][j] = 1 + dp[i - 1][j - 1]; // helper(text1, text2, index1 - 1, index2 - 1, dp);
                else {
                     dp[i][j] = 0 + Math.max(dp[i - 1][j], dp[i][j - 1]); // Math.max(helper(text1, text2, index1
                                                                                // - 1, index2, dp), helper(text1,
                                                                                // text2, index1, index2 - 1, dp));
                }
            }
        }

        return dp[index1][index2];
    }
}