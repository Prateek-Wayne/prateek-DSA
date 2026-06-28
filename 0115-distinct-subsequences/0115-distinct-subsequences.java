class Solution {
    public int numDistinct(String s, String t) {
        int index1 = s.length();
        int index2 = t.length();
        int[][] dp = new int[index1 + 1][index2 + 1];
        for (int i = 0; i <= index1; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[index1][index2];
    }
}