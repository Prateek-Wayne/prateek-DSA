class Solution {
       public static int longestCommonSubsequence(String text1, String text2) {
        int index1 = text1.length();
        int index2 = text2.length();
        int[][] dp = new int[index1 + 1][index2 + 1];
        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        // Print dp array
        for (int i = 0; i <= index1; i++) {
            System.out.println(Arrays.toString(dp[i]));
        }
        return dp[index1][index2];
    }
    public int minDistance(String word1, String word2) {
        int l1=word1.length();
        int l2=word2.length();
        int l3=longestCommonSubsequence(word1,word2);
        return l1+l2-2*l3;
    }
}