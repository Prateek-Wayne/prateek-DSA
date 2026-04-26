class Solution {
    int solve(String s, int index, int[] dp) {
        int n = s.length();
        if (index == n) {
            return 1;
        }
        if (s.charAt(index) == '0')
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int result = solve(s, index + 1, dp);
        if (index + 1 < n) {
            if (s.charAt(index) == '1' || (s.charAt(index) == '2' && s.charAt(index + 1) <= '6')) {
                result += solve(s, index + 2, dp);
            }
        }
        return dp[index] = result;
    }

    public int numDecodings(String s) {
        int n = s.length();
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return solve(s, 0, dp);
    }
}