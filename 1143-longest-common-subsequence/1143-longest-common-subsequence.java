class Solution {
   int helper(String text1, String text2, int index1, int index2, int[][] dp) {
        if (index1 == 0 || index2 == 0)
            return 0;
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (text1.charAt(index1 - 1) == text2.charAt(index2 - 1))
            return 1 + helper(text1, text2, index1 - 1, index2 - 1, dp);
        return dp[index1][index2] = Math.max(helper(text1, text2, index1 - 1, index2, dp),
                helper(text1, text2, index1, index2 - 1, dp));
    }

    public int longestCommonSubsequence(String text1, String text2) {
        int index1 = text1.length();
        int index2 = text2.length();
        int[][] dp = new int[index1 + 1][index2 + 1];
        for (int[] temp : dp)
            Arrays.fill(temp, -1);
        return helper(text1, text2, index1, index2, dp);
    }
}