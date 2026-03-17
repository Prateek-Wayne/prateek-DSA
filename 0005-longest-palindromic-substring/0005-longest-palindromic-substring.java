class Solution {
     Boolean solve(String s, int i, int j, int[][] dp) {
        if (i >= j)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j] == 0 ? false : true;
        if (s.charAt(i) == s.charAt(j)) {

            Boolean ans = solve(s, i+1, j-1, dp);
            dp[i][j] = ans == true ? 1 : 0;
            return ans;
        }
        return false;
    }

    public String longestPalindrome(String s) {
        int n = s.length();
        StringBuilder ans = new StringBuilder();
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            int[] temp = new int[n + 1];
            Arrays.fill(temp, -1);
            dp[i] = temp;
        }
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(s, i, j, dp)) {
                    if (maxLength < j - i + 1) {
                        maxLength = j - i + 1;
                        ans.delete(0, ans.length());
                        ans = new StringBuilder(s.subSequence(i, j + 1));
                    }
                }
            }
        }
        return ans.toString();
    }
}