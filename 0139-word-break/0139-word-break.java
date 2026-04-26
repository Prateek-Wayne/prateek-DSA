class Solution {
  Set<String> st = new HashSet<>();

    boolean solve(String s, int idx, Boolean[] dp) {
        int n = s.length();
        if (idx == n)
            return true;
        if (dp[idx] != null)
            return dp[idx];
        if (st.contains(s.substring(idx)))
            return true;
        for (int l = 1; idx + l <= n; l++) {
            String temp = s.substring(idx, idx + l);
            if (st.contains(temp) && solve(s, idx + l, dp))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {

        for (String str : wordDict) {
            st.add(str);
        }
        int n = s.length();
        Boolean[] dp = new Boolean[n + 1];
        return solve(s, 0, dp);
    }
}