class Solution {
  int helper(String s1, String s2, int index1, int index2, int[][] dp) {
        if (index1 < 0 || index2 < 0)
            return 0;
        // pick...
        if (s1.charAt(index1) == s2.charAt(index2))
            return 1 + helper(s1, s2, index1 - 1, index2 - 1, dp);
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        int left = helper(s1, s2, index1 - 1, index2, dp);
        int right = helper(s1, s2, index1, index2 - 1, dp);
        return dp[index1][index2] = Math.max(left, right);

    }

    public int longestPalindromeSubseq(String s) {
        int index = s.length();
        String s2 = new String("");
        for (int i = index - 1; i >= 0; i--) {
            s2 += s.charAt(i);
        }
        int[][] dp = new int[index + 1][index + 1];
        for (int i = 0; i <= index; i++) {
            int[] temp = new int[index + 1];
            Arrays.fill(temp, -1);
            dp[i] = temp;
        }
        return helper(s, s2, index - 1, index - 1, dp);

    }
}