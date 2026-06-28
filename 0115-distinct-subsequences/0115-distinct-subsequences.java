class Solution {
 int helper(String s, String t, int index1, int index2, Integer[][] dp) {
        // base...
        if (index2 < 0)
            return 1;
        if (index1 < 0)
            return 0;
        if (dp[index1][index2] != null)
            return dp[index1][index2];

        if (s.charAt(index1) == t.charAt(index2)) {
            return dp[index1][index2] = helper(s, t, index1 - 1, index2 - 1, dp) + helper(s, t, index1 - 1, index2, dp);
        } else {
            return dp[index1][index2] = helper(s, t, index1 - 1, index2, dp);
        }
    }

    public int numDistinct(String s, String t) {
        int index1 = s.length();
        int index2 = t.length();
        Integer[][] dp = new Integer[index1][index2];

        return helper(s, t, index1 - 1, index2 - 1, dp);
    }
}