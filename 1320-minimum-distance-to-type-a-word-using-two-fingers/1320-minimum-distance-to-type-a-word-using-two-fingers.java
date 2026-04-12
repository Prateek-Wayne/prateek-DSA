class Solution {
    int cal(int a, int b) {
        return Math.abs(a / 6 - b / 6) + Math.abs(a % 6 - b % 6);
    }

    public int minimumDistance(String word) {
        int n = word.length();
        int[][][] dp = new int[n + 1][26][26];

        for (int i = 0; i < n; i++) {
            int t = word.charAt(i) - 'A';

            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dp[i + 1][j][k] = 1000000;
                }
            }

            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dp[i + 1][j][t] = Math.min(dp[i + 1][j][t], dp[i][j][k] + cal(k, t));
                    dp[i + 1][t][k] = Math.min(dp[i + 1][t][k], dp[i][j][k] + cal(j, t));
                }
            }
        }

        int ans = 1000000;
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                ans = Math.min(ans, dp[n][j][k]);
            }
        }

        return ans;
    }
}